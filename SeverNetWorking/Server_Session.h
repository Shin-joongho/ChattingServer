#pragma once
#include "Session.h"
#include "Send_RecvBuffer.h"
#include "Protocol.pb.h"
#include "Send_Time.h"

class MainServer : public Session
{
public:
	void Child_Recv(int32 bytes) override;
	void Child_Close() override
	{
		std::cout << "Disconnect" << std::endl;
	}

public:
	void Login_Accept();
	void Server_BroadCast();
	void Server_DM();

private:
	void GetError(int16 errorcode);
};