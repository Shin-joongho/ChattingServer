#pragma once
#include "TYPE.h"
#include <map>
#include <ctime>

//서버 패킷
class Chat_Packet
{
public :
	void Login_Packet(Session* session);
	void Login_Packet(Session* session, char* userid);

	char Read_Header(Session* session);
	void Send_Header(std::string msg, Session* session);

private:
	void Read_Message(Session* session);
	void Send_Message(std::string msg, Session* session);

	void Print_Time();
};

/*
 /                  header                   /
 type / user id / filename(other id) / size / data /
  1   /   10    /    10             /  4       ~
*/ 