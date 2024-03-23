#include "pch.h"
#include "Session.h"

Session::Session()
{
	_socket = Socket::CreateSocket();
}

Session::~Session()
{
	std::cout << "Socket Close" << std::endl;
	Socket::Socket_Close(_socket);
}

HANDLE Session::Gethandle()
{
	if (_socket == INVALID_SOCKET)
		return nullptr;

	return reinterpret_cast<HANDLE>(_socket);
}

void Session::Dispatch(IocpEvent* iocpEvent, uint32 bytes)
{
	//iocp queue에서 처리 후 

	IocpType iocpType = iocpEvent->_type;
	switch (iocpType)
	{
	case IocpType::CONNECT:
		StartConnect();
		break;

	case IocpType::DISCONNECT:
		Disconnect();
		break;

	case IocpType::RECV:
		Recv(bytes);
		break;

	case IocpType::SEND:
		Send(bytes);
		break;

	default:
		break;
	}
}

void Session::GetError(int16 errorcode)
{
	std::cout << "SessionError : " << errorcode << std::endl;
}

std::string Session::UTF8_to_String(const char* utf8)
{
	int length = MultiByteToWideChar(CP_UTF8, 0, utf8, (int)strlen(utf8) + 1, NULL, NULL);
	wchar_t* pbuf = new wchar_t[length + 1];
	MultiByteToWideChar(CP_UTF8, 0, utf8, (int)strlen(utf8) + 1, pbuf, length);
	pbuf[length] = 0;
	std::string str = std::string(CT2CA(CStringA(pbuf)));
	delete[] pbuf;

	return str;
}

std::string Session::String_to_UTF8(std::string str)
{
	std::wstring unicode_string(CA2W(str.c_str()));
	std::string result(CW2A(unicode_string.c_str(), CP_UTF8));
	return result;
}

void Session::StartClose()
{
	_disconnectEvent.Init();
	_disconnectEvent.iocpeventRef = shared_from_this();

	if (false == Socket::DisconnectEx(_socket, &_disconnectEvent, TF_REUSE_SOCKET, 0))
	{
		int16 errorcode = WSAGetLastError();
		if (errorcode != WSA_IO_PENDING)
		{
			_disconnectEvent.iocpeventRef = nullptr;
			GetError(errorcode);
			return;
		}
	}
}

void Session::SessionClose()
{
	_isconnect.store(false);

	std::cout << "Close" << std::endl;

	StartClose();

	Child_Close();
	Socket::Socket_Close(_socket);
	GetService()->ReleaseSession(GetSession());
}

void Session::Disconnect()
{
	_disconnectEvent.iocpeventRef = nullptr; //share ptr 제거
	GetService()->RlsNmToSession(GetSession(), _nickName);
}

void Session::StartConnect()
{
	GetService()->AddSession(GetSession());

	_isconnect.store(true);
	_connectEvent.iocpeventRef = nullptr;

	Child_Connect();
	StartRecv();
}

bool Session::BeforeConnect()
{
	if (_isconnect)
		return false;

	if (GetService()->GetServiceType() != ServiceType::CLIENT)
		return false;

	if (Socket::SetReuseAddress(_socket, true) == false)
		return false;

	if (Socket::BindAnySocket(_socket, 0) == false)
		return false;

	_connectEvent.Init();
	_connectEvent.iocpeventRef = shared_from_this();

	SOCKADDR_IN address = GetService()->GetNetAddress().GetSockAddr();
	DWORD byte = 0;
	if (false == Socket::ConnectEx(_socket, reinterpret_cast<SOCKADDR*>(&address)
		, sizeof(address), NULL, 0, &byte, &_connectEvent))
	{
		int16 errorcode = WSAGetLastError();
		if (errorcode != WSA_IO_PENDING)
		{
			_connectEvent.iocpeventRef = nullptr;
			GetError(errorcode);
			return false;
		}
	}

	return true;
}

void Session::StartRecv()
{
	if (_isconnect == false)
		return;

	_recvEvent.Init();
	_recvEvent.iocpeventRef = shared_from_this();

	WSABUF wsabuf;
	wsabuf.buf = _recvBuffer.Get_WriteBuffer();
	wsabuf.len = _recvBuffer.PacketSize();

	DWORD recvLen = 0;
	DWORD flag = 0;

	if (SOCKET_ERROR == WSARecv(_socket, &wsabuf, 1, &recvLen, &flag, &_recvEvent, NULL))
	{
		int16 errorcode = WSAGetLastError();
		if (errorcode != WSA_IO_PENDING)
		{
			GetError(errorcode);
		}

	}
	//가장 먼저 Recv하는 곳
}

void Session::Recv(int32 bytes)
{
	_recvEvent.iocpeventRef = nullptr; //share ptr 제거

	if (bytes == 0)
	{
		SessionClose();
		return;
	}

	if (_recvBuffer.Div_Buffer(bytes))
	{
		Child_Recv(bytes);
		_recvBuffer.Set_ReadPos(_recvBuffer.GetBufferSize());
	}

	StartRecv();		
}

void Session::BeforeSend(SendBufferRef sender)
{
	if (_isconnect == false)
		return;

	bool queueLock = false;

	{
		LockGuard lg(_mutex);

		_sendQueue.push(sender);

		if (_isSend.exchange(true) == false)
			queueLock = true;
	}
	if (queueLock)
		StartSend();
}

void Session::StartSend()
{
	if (_isconnect == false)
		return;

	_sendEvent.Init();
	_sendEvent.iocpeventRef = shared_from_this();

	{
		LockGuard lg(_mutex);

		while (!_sendQueue.empty())
		{
			_sendEvent._sendBuffer.push_back(_sendQueue.front());
			_sendQueue.pop();
		}
	}

	std::vector<WSABUF> wsabufs;
	wsabufs.reserve(_sendEvent._sendBuffer.size());

	for (SendBufferRef buffer : _sendEvent._sendBuffer)
	{
		WSABUF wsabuf;
		wsabuf.buf = buffer->GetBuffer();
		wsabuf.len = buffer->GetSize();

		wsabufs.push_back(wsabuf);
	}

	DWORD flag = 0;
	DWORD byte = 0;
	if (SOCKET_ERROR == WSASend(_socket, wsabufs.data()
		, static_cast<DWORD>(wsabufs.size()), &byte, flag, &_sendEvent, NULL))
	{
		int16 errorcode = WSAGetLastError();
		if (errorcode != WSA_IO_PENDING)
		{
			GetError(errorcode);
		}
	}
}

void Session::Send(int32 bytes)
{
	_sendEvent.iocpeventRef = nullptr;
	_sendEvent._sendBuffer.clear();

	if (bytes == 0)
	{
		SessionClose();
		return;
	}

	Child_Send();

	if (_sendQueue.empty())
		_isSend.store(false);
	else
		StartSend();
}


