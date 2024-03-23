#include "Chat_Packet.h"

void Chat_Packet::Login_Packet(Session* session)
{
	int phead = 0;

	char* type = new char[P_TYPE];
	type = session->recvBuffer;
	phead = P_TYPE;

	char* name = new char[USERID];
	name = session->recvBuffer + phead;

	memcpy_s(session->userid, USERID, name, USERID);

	std::cout << session->userid << "님이 로그인 하였습니다." << std::endl;
}

void Chat_Packet::Login_Packet(Session* session, char* userid)
{
	int size = P_TYPE + USERID;
	char* buffer = new char[size];
	char type[P_TYPE] = { HD_TYPE::LOGIN };
	memset(buffer, 0, size); //초기화

	memcpy_s(buffer, P_TYPE, (char*)type, P_TYPE);
	memcpy_s(buffer + P_TYPE, USERID, userid, USERID);

	char* prevbuf = session->Swsabuf.buf;
	session->Swsabuf.buf = buffer;
	session->Swsabuf.len = size;

	free(prevbuf);
}

char Chat_Packet::Read_Header(Session* session)
{
	//receivebuffer page-locking

	char type = session->recvBuffer[0]; //type

	if (type == HD_TYPE::MESSAGE)
	{
		Read_Message(session);
	}
	else if (type == HD_TYPE::HEART)
	{
		
	}	
	return type;
}

void Chat_Packet::Send_Header(std::string msg, Session* session)
{

	if (msg[0] == '/')
	{
		if (msg[1] == 'd' || msg[1] == 'D') //direct message
		{

		}
		else if (msg[1] == 'f' || msg[1] == 'F') //send file
		{

		}
	}
	else
	{
		Send_Message(msg, session);
	}
	

	return;
}

void Chat_Packet::Read_Message(Session* session)
{
	int head = P_TYPE; //패킷 타입을 이미 확인했으니 head를 그만큼 이동하고 시작
	char* userid = (char*)malloc(USERID);
	char* id_filename = (char*)malloc(FILE_NAME);  //file일 경우 filename
	char* p_size = (char*)malloc(PData_SIZE);

	memset(userid, 0, USERID); //초기화
	memset(id_filename, 0, FILE_NAME); //초기화
	memset(p_size, 0, PData_SIZE); //초기화

	memcpy_s(userid, USERID, session->recvBuffer + head, USERID);
	head += USERID;

	memcpy_s(id_filename, FILE_NAME, session->recvBuffer + head, FILE_NAME);
	head += FILE_NAME;

	//p_size = session->recvBuffer + head;
	memcpy_s(p_size, PData_SIZE, session->recvBuffer + head, PData_SIZE);
	head += PData_SIZE;

	int size = atoi(p_size);

	char* buffer = (char*)malloc(size);
	memset(buffer, 0, size); //초기화

	memcpy_s(buffer, size, session->recvBuffer + head, size);

	Print_Time();
	std::cout << userid << ": " << buffer << std::endl;

	free(buffer);
	free(userid);
	free(id_filename);
	free(p_size);

	return;
}

void Chat_Packet::Send_Message(std::string msg, Session* session)
{
	unsigned int len = msg.length() + 1; //'\0'추가

	int size = P_TYPE + USERID + FILE_NAME + PData_SIZE;
	int phead = 0;
	char* buffer = (char*)malloc(size + len); // buffer

	char type[P_TYPE] = { HD_TYPE::MESSAGE }; // packet type        

	std::ostringstream str_len;
	//str_len << std::setw(4) << std::setfill('0') << len;

	char* plen = new char[PData_SIZE]; //packet size
	memcpy_s(plen, PData_SIZE, str_len.str().c_str(), PData_SIZE);

	char* p_msg = new char[len]; //msg
	memcpy_s(p_msg, len, msg.c_str(), len);

	memcpy_s(buffer, P_TYPE, (char*)type, P_TYPE);
	phead += P_TYPE;

	memcpy_s(buffer + phead, USERID, session->userid, USERID);
	phead += USERID;

	memcpy_s(buffer + phead, FILE_NAME, session->userid, FILE_NAME);
	phead += FILE_NAME;

	memcpy_s(buffer + phead, PData_SIZE, plen, PData_SIZE);
	phead += PData_SIZE;

	memcpy_s(buffer + phead, len, p_msg, len);

	session->Swsabuf.buf = buffer;
	session->Swsabuf.len = size + len;

	return;
}

void Chat_Packet::Print_Time()
{/*
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::chrono::time_point< std::chrono::system_clock, std::chrono::days> dp
		= std::chrono::floor< std::chrono::days>(now);

	std::chrono::year_month_day ymd{ dp };
	std::chrono::hh_mm_ss time{ std::chrono::floor<std::chrono::milliseconds>(now - dp) };

	std::cout << "[" << ymd.year() << "-" << ymd.month() << "-" << ymd.day() << " "
		<< time.hours() << " " << time.minutes() << " " << time.seconds() << "] ";*/
}


