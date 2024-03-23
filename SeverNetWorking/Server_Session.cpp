#include "pch.h"
#include "Server_Session.h"

void MainServer::Child_Recv(int32 bytes)
{
	switch (_recvBuffer.GetType())
	{
	case Packet_Type::LOGIN:
		Login_Accept();
		break;

	case Packet_Type::BROADCAST:
		Server_BroadCast();
		break;

	case Packet_Type::DM:
		Server_DM();
		break;
	default:
		break;
	}


}

void MainServer::Login_Accept()
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
		
	_nickName = login.user_name();

	GetService()->AddNmToSession(GetSession(), _nickName);

	SendBufferRef sendbuffer = std::make_shared<SendBuffer>();
	sendbuffer->CopyData(_recvBuffer);
	BeforeSend(sendbuffer);

	std::static_pointer_cast<ServerService>(GetService())->SaveLog(_nickName, "Login");
	std::cout << _nickName << " Server LOGIN " << std::endl;
	
}

void MainServer::Server_BroadCast()
{
	SendBufferRef sendbuffer = std::make_shared<SendBuffer>();
	sendbuffer->CopyData(_recvBuffer);
	
	Protocol::BuffData bufdata;
	if (false == bufdata.ParseFromArray(_recvBuffer.Get_ReadData(), _recvBuffer.GetSize()))
	{
		GetError(PARSE_ERROR);
		return;
	}
	std::string msg = UTF8_to_String(bufdata.message_all().c_str()); //한글 사용시 UTF8 -> 유니코드로 변환
	std::static_pointer_cast<ServerService>(GetService())->SaveLog(_nickName, msg); //Log

	std::static_pointer_cast<ServerService>(GetService())->BroadCast(sendbuffer, GetSession());
}

void MainServer::Server_DM()
{
	std::string keyname;

	SendBufferRef sendbuffer = std::make_shared<SendBuffer>();
	sendbuffer->CopyData(_recvBuffer);

	Protocol::BuffData bufdata;
	if (false == bufdata.ParseFromArray(_recvBuffer.Get_ReadData(), _recvBuffer.GetSize()))
	{
		GetError(PARSE_ERROR);
		return;
	}

	std::string msg = UTF8_to_String(bufdata.message_all().c_str()); // 한글 사용시 UTF8->유니코드로 변환
	std::static_pointer_cast<ServerService>(GetService())->SaveLog(_nickName, msg);

	keyname = bufdata.recv_user();
	
	if (false == GetService()->SendToOneSession(sendbuffer, keyname)) // 귓속말할 유저가 있는지 확인
	{																
		bufdata.set_send_time(Send_Time::GetDateTime());
		bufdata.set_send_user("Admin");
		bufdata.set_recv_user(_nickName);
		bufdata.set_message_all(u8"사용자가 없습니다.");

		sendbuffer->CopyData(Packet_Type::BROADCAST, bufdata); //유저가 없을시 전송한 유저에게 해당 유저가 없다고 전송
		BeforeSend(sendbuffer);
	}
		
}

void MainServer::GetError(int16 errorcode)
{
	std::cout << "Server Error : " << errorcode << std::endl;
}


