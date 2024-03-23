#include "pch.h"
#include "Service.h"

Service::Service(ServiceType type, NetAddress netaddress, IOCPRef iocpRef, SessionFac sessionFac, uint32 maxSession)
	: _type(type), _netaddress(netaddress), _iocpRef(iocpRef), _sessionFac(sessionFac), _maxSession(maxSession)
{
	return;
}

bool Service::SendToOneSession(SendBufferRef sendbuffer, std::string nickName)
{
	return _type != ServiceType::CLIENT;
}

SessionRef Service::CreateSession()
{
	SessionRef sessionRef = _sessionFac();
	sessionRef->SetService(shared_from_this());

	//IOCP 등록
	if (false == _iocpRef->Register(sessionRef))
		return nullptr;

	return sessionRef;
}

void Service::AddSession(SessionRef session)
{
	LockGuard lock(_lock);
	_sessions.insert(session);
	_sessionCount++;
}

void Service::ReleaseSession(SessionRef session)
{
	LockGuard lock(_lock);
	_sessions.erase(session);
	_sessionCount--;
}

void Service::GetError(int errorcode)
{
	std::cout << "Service Error : " << errorcode << std::endl;
}

ServerService::ServerService(NetAddress netaddress, IOCPRef iocpRef, SessionFac sessionFac, uint32 maxSession)
	: Service(ServiceType::SERVER, netaddress, iocpRef, sessionFac, maxSession)
{
}

bool ServerService::Start()
{
	if (mysql.Init() == false)
	{
		std::cout << "연결할 수 없습니다." << std::endl;
		return false;
	}

	if (CanStart() == false)
		return false;

	_listener = std::make_shared<Listener>();
	if (_listener == nullptr)
		return false;

	ServerServiceRef service = std::static_pointer_cast<ServerService>(shared_from_this());
	if (_listener->Init(service) == false)
		return false;

	return true;
}

void ServerService::AddNmToSession(SessionRef session, std::string name)
{
	LockGuard lg(_mapLock);
	_nmToSession.insert(std::pair<std::string, SessionRef>(name, session));

	return;
}

void ServerService::RlsNmToSession(SessionRef session, std::string name)
{
	LockGuard lg(_mapLock);
	auto find = _nmToSession.find(name);
	if (find != _nmToSession.end())
		_nmToSession.erase(find);

	return;
}

bool ServerService::SendToOneSession(SendBufferRef sendbuffer, std::string nickName)
{
	SessionRef findSession = FindNmToSession(nickName);
	if (findSession == nullptr)
		return false;

	findSession->BeforeSend(sendbuffer);

	return true;
}

SessionRef ServerService::FindNmToSession(std::string findName)
{
	LockGuard lg(_mapLock);

	auto find = _nmToSession.find(findName);
	if (find == _nmToSession.end())
		return nullptr;

	return find->second;
}

bool ServerService::SaveLog(std::string nickName, std::string log)
{
	return mysql.SaveLog(nickName, log);
}

void ServerService::BroadCast(SendBufferRef sendbuffer)
{
	LockGuard lg(_lock);

	for (SessionRef session : _sessions)
	{
		session->BeforeSend(sendbuffer);
	}
}

void ServerService::BroadCast(SendBufferRef sendbuffer, SessionRef send_session)
{
	LockGuard lg(_lock);
	for (SessionRef session : _sessions)
	{
		if (session == send_session)
			continue;

		session->BeforeSend(sendbuffer);
	}
}

ClientService::ClientService(NetAddress netaddress, IOCPRef iocpRef, SessionFac sessionFac, uint32 maxSession)
	: Service(ServiceType::CLIENT, netaddress, iocpRef, sessionFac, maxSession)
{
}

ClientService::ClientService(NetAddress netaddress, IOCPRef iocpRef, SessionFac sessionFac)
	: Service(ServiceType::CLIENT, netaddress, iocpRef, sessionFac, 1)
{
}

bool ClientService::Start()
{
	std::pair<bool, std::string> result = Login_Accept();

	if (result.first == false)
		return false;

	if (CanStart() == false)
		return false;

	SessionRef session = CreateSession();
	session->SetNickName(result.second);
	if (session->BeforeConnect() == false)
		return false;

	return true;
}

void ClientService::AddSession(SessionRef session)
{
	LockGuard lg(_lock);
	if(_userSession == nullptr)
		_userSession = session;

	_sessions.insert(session);
	_sessionCount++;
}

void ClientService::ReleaseSession(SessionRef session)
{
	LockGuard lg(_lock);
	if (_userSession == session)
	{
		_userSession = nullptr;

		if (_sessions.empty() == false)
		{
			auto next_session = _sessions.begin();
			_userSession = *next_session;
		}
		
	}
		
	_sessions.erase(session);
	_sessionCount--;
}

std::pair<bool, std::string> ClientService::Login_Accept()
{
	bool IsLogin = false;
	std::string id;

	if (mysql.Init() == false)
	{
		std::cout << "연결할 수 없습니다." << std::endl;
		return std::pair<bool, std::string>(false, "NONE");
	}
	
	while (IsLogin == false)
	{
		std::cout << "로그인 시 L, 회원가입시 S 입력" << std::endl;
		{
			std::string choose;
			std::string pw;
			std::cin >> choose;

			if (choose == "L")
			{
				std::cout << "ID : ";
				std::cin >> id;
				std::cout << "PW : ";
				std::cin >> pw;

				IsLogin = mysql.Login(id, pw);
			}
			else if (choose == "S")
			{
				std::cout << "ID 생성 : ";
				std::cin >> id;
				std::cout << "PW : ";
				std::cin >> pw;

				mysql.SignUp(id, pw);
			}
			else
				return std::pair<bool, std::string>(false, "NONE");
		}
	}
	
	mysql.Close();
	return std::pair<bool, std::string>(true, id);
}

std::vector<std::string> ClientService::Msg_Split(std::string msg, char delimiter)
{
	std::istringstream stream(msg);
	std::string split_msg;
	std::vector<std::string> result;
	int count = 0;
	while (std::getline(stream, split_msg, delimiter))
	{
		result.push_back(split_msg);
		count++;
		if (count >= 2)
		{
			delimiter = '\n';
		}
	}

	return result;
}

bool ClientService::Client_Send(std::string msg)
{
	Packet_Type type = Packet_Type::P_NULL;
	std::string recv, message;

	if (msg[0] == '/')
	{
		if (msg[1] == 'r' || msg[1] == 'R')
		{
			std::vector<std::string> msg_split = Msg_Split(msg, ' ');
			if (msg_split.size() > 3)
			{
				GetError(SPLIT_ERROR);
				return false;
			}
			type = Packet_Type::DM;
			recv = msg_split[1];
			message = msg_split[2];
		}
		else if (msg[1] == 'q' || msg[1] == 'Q')
		{
			_userSession->SessionClose();
		}
		else
		{
			std::cout << "NONE" << std::endl;
		}
	}
	else
	{
		type = Packet_Type::BROADCAST;
		recv = "BROADCAST";
		message = msg;
	}

	std::string utf8_msg = _userSession->String_to_UTF8(message);

	Protocol::BuffData bufdata;
	bufdata.set_send_time(Send_Time::GetDateTime());
	bufdata.set_send_user(_userSession->GetNickName());
	bufdata.set_recv_user(recv);
	bufdata.set_message_all(utf8_msg);

	SendBufferRef sendbuffer = std::make_shared<SendBuffer>();
	if (false == sendbuffer->CopyData(type, bufdata))
		return false;

	_userSession->BeforeSend(sendbuffer);
	return true;
}

void ClientService::GetError(int16 errorcode)
{
	std::cout << "Client Service Error : " << errorcode << std::endl;
}
