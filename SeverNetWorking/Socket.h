#pragma once
#include <mswsock.h>
#include "NetAddress.h"
#include <mstcpip.h>

#pragma comment(lib,"mswsock.lib") 

class Socket
{
public:
	static LPFN_CONNECTEX		ConnectEx;
	static LPFN_DISCONNECTEX	DisconnectEx;
	static LPFN_ACCEPTEX		AcceptEx;

public:
	static void Socket_Init();
	static void Socket_Clear();
	static void Socket_Close(SOCKET& socket);

	static bool BindWindowsFunction(SOCKET& socket, GUID guid, LPVOID* fn);

	static SOCKET CreateSocket();
	static bool BindSocket(SOCKET& socket, NetAddress SockAddr);
	static bool BindAnySocket(SOCKET& socket, uint16 port);
	static bool ListenSocket(SOCKET& socket, uint32 backlog);

	//SOCKET Setting
public:
	//close시 데이터 처리
	static bool SetLinger(SOCKET socket, uint16 onoff, uint16 linger);
	//port재사용
	static bool SetReuseAddress(SOCKET socket, bool flag);
	//송신, 수신 버퍼 크기 조정
	static bool SetRecvBufferSize(SOCKET socket, int32 size);
	static bool SetSendBufferSize(SOCKET socket, int32 size);
	//nagle알고리즘 사용 유무
	static bool SetTcpNoDelay(SOCKET socket, bool flag);
	//keep alive 사용
	static bool HeartBeatSocket(SOCKET socket);

	//소켓 옵션 설정
	static bool SetUpdateAcceptSocket(SOCKET socket, SOCKET listenSocket);


};

template<typename T>
static inline bool SetSockOpt(SOCKET& socket, int32 level, int32 optName, T optVal)
{
	return SOCKET_ERROR != ::setsockopt(socket, level, optName, reinterpret_cast<char*>(&optVal), sizeof(T));
}