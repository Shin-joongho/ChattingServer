#include "pch.h"
#include "Client_Session.h"
//
// Client
//

void MainClient::Child_Connect()
{
	Protocol::Login login;
	login.set_allow(true);
	login.set_user_name(_nickName);

	SendBufferRef sendbuffer = std::make_shared<SendBuffer>();
	sendbuffer->CopyData(login);
	BeforeSend(sendbuffer);
}

void MainClient::Child_Recv(int32 bytes)
{
	switch (_recvBuffer.GetType())
	{
	case Packet_Type::LOGIN:
		Login_Accept();
		break;

	case Packet_Type::BROADCAST:
		B_D_Recv(Packet_Type::BROADCAST);
		break;

	case Packet_Type::DM:
		B_D_Recv(Packet_Type::DM);
		break;

	default:
		break;
	}
		
}

void MainClient::Login_Accept()
{
	Protocol::Login login;
	if (false == login.ParseFromArray(_recvBuffer.Get_ReadData(), _recvBuffer.GetSize()))
	{
		GetError(PARSE_ERROR);
		StartClose();
		return;
	}
	
	if (login.allow() == false)
	{
		StartClose();
		return;
	}
	_IsLogin = true;
	std::cout << _nickName << " Client LOGIN " << std::endl;
	
}

void MainClient::B_D_Recv(Packet_Type type)
{
	if (_IsLogin == false)
		return;

	Protocol::BuffData bufdata;
	if (false == bufdata.ParseFromArray(_recvBuffer.Get_ReadData(), _recvBuffer.GetSize()))
	{
		GetError(PARSE_ERROR);
		return;
	}

	std::string msg = UTF8_to_String(bufdata.message_all().c_str());

	if(type == Packet_Type::BROADCAST)
		msg = "<" + bufdata.send_time() + "> " + bufdata.send_user() + " : " + msg;
	else if(type == Packet_Type::DM)
		msg = "<" + bufdata.send_time() + "> " + bufdata.send_user() + "¥‘¿∏∑Œ ∫Œ≈Õ : " + msg;
	WriteLock(msg);
	
}

void MainClient::GetError(int16 errorcode)
{
	std::cout << "Client Error : " << errorcode << std::endl;
}

void MainClient::WriteLock(std::string msg)
{
	LockGuard lg(_writeLock);
	std::cout << msg << std::endl;
}
