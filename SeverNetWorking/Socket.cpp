#include "pch.h"
#include "Socket.h"

LPFN_CONNECTEX		Socket::ConnectEx = nullptr;
LPFN_DISCONNECTEX	Socket::DisconnectEx = nullptr;
LPFN_ACCEPTEX		Socket::AcceptEx = nullptr;


void Socket::Socket_Init()
{
	WSADATA wsadata;
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
	{
		std::cout << "WSAStartup Error" << std::endl;
		return;
	}
	SOCKET socket = CreateSocket();

	BindWindowsFunction(socket, WSAID_CONNECTEX, reinterpret_cast<LPVOID*>(&ConnectEx));
	BindWindowsFunction(socket, WSAID_DISCONNECTEX, reinterpret_cast<LPVOID*>(&DisconnectEx));
	BindWindowsFunction(socket, WSAID_ACCEPTEX, reinterpret_cast<LPVOID*>(&AcceptEx));

	Socket_Close(socket);
}

void Socket::Socket_Clear()
{
	WSACleanup();
}

void Socket::Socket_Close(SOCKET& socket)
{
	if (socket == INVALID_SOCKET)
		return;
	
	closesocket(socket);
	socket = INVALID_SOCKET;
}

bool Socket::BindWindowsFunction(SOCKET& socket, GUID guid, LPVOID* fn)
{
	DWORD bytes = 0;
	return SOCKET_ERROR != WSAIoctl(socket, SIO_GET_EXTENSION_FUNCTION_POINTER, &guid, sizeof(guid), fn, sizeof(*fn), OUT & bytes, NULL, NULL);
}

bool Socket::HeartBeatSocket(SOCKET socket)
{
	tcp_keepalive tcpki;
	tcpki.onoff = 1;
	//tcpki.keepalivetime은 default 2초를 사용
	tcpki.keepaliveinterval = 1000;
	DWORD bytes = 0;
	return SOCKET_ERROR != WSAIoctl(socket, SIO_KEEPALIVE_VALS, &tcpki, sizeof(tcp_keepalive), 0 , 0 , &bytes, NULL, NULL);
}

SOCKET Socket::CreateSocket()
{
	//tcp, IOCP사용을 위한 OVERLAPPED
	return WSASocketW(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);
}

bool Socket::BindSocket(SOCKET& socket, NetAddress SockAddr)
{
	return SOCKET_ERROR != bind(socket, reinterpret_cast<const SOCKADDR*>(&SockAddr.GetSockAddr()), sizeof(SOCKADDR_IN));
}

bool Socket::BindAnySocket(SOCKET& socket, uint16 port)
{
	SOCKADDR_IN sockaddr;
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	sockaddr.sin_port = htons(port);

	return SOCKET_ERROR != bind(socket, reinterpret_cast<const SOCKADDR*>(&sockaddr), sizeof(SOCKADDR_IN));
}

bool Socket::ListenSocket(SOCKET& socket, uint32 backlog)
{
	return SOCKET_ERROR != listen(socket, backlog);
}

bool Socket::SetLinger(SOCKET socket, uint16 onoff, uint16 linger)
{
	LINGER option;
	option.l_onoff = onoff;
	option.l_linger = linger;
	return SetSockOpt(socket, SOL_SOCKET, SO_LINGER, option);
}

//setopt
bool Socket::SetReuseAddress(SOCKET socket, bool flag)
{
	return SetSockOpt(socket, SOL_SOCKET, SO_REUSEADDR, flag);
}

bool Socket::SetRecvBufferSize(SOCKET socket, int32 size)
{
	return SetSockOpt(socket, SOL_SOCKET, SO_RCVBUF, size);
}

bool Socket::SetSendBufferSize(SOCKET socket, int32 size)
{
	return SetSockOpt(socket, SOL_SOCKET, SO_SNDBUF, size);
}

bool Socket::SetTcpNoDelay(SOCKET socket, bool flag)
{
	return SetSockOpt(socket, IPPROTO_TCP, TCP_NODELAY, flag);
}

// ListenSocket의 특성을 ClientSocket에 그대로 적용
bool Socket::SetUpdateAcceptSocket(SOCKET socket, SOCKET listenSocket)
{
	return SetSockOpt(socket, SOL_SOCKET, SO_UPDATE_ACCEPT_CONTEXT, listenSocket);
}