#include "pch.h"
#include "Listener.h"

Listener::~Listener()
{
	Socket::Socket_Close(_socket);

	for (AcceptEvent* acceptEvent : _acceptEvents)
	{
		// TODO
		delete(acceptEvent);
	}
}

bool Listener::Init(ServerServiceRef service)
{
	_service = service;
	_socket = Socket::CreateSocket();
	if (_socket == INVALID_SOCKET)
	{
		GetError(SOCKET_INVALID);
		return false;
	}
	// listen을 담당하는 이 객체를 IOCP로 감지
	if (false == _service->GetIOCP()->Register(shared_from_this()))
	{
		GetError(IOCP_FALSE);
		return false;
	}
	if (Socket::SetReuseAddress(_socket, true) == false)
		return false;

	if (Socket::SetLinger(_socket, 0, 0) == false)
		return false;

	if (false == Socket::BindSocket(_socket, service->GetNetAddress()))
	{
		GetError(BIND_ERROR);
		return false;
	}

	if (false == Socket::ListenSocket(_socket, SOMAXCONN))
	{
		GetError(LISTEN_ERROR);
		return false;
	}
	
	for (int i = 0; i < 5; i++)
	{
		AcceptEvent* acceptEvent = new AcceptEvent();
		acceptEvent->iocpeventRef = shared_from_this();
		_acceptEvents.push_back(acceptEvent);
		Accept(acceptEvent);
	}

	return true;
	
}

void Listener::Accept(AcceptEvent* acceptEvent)
{
	SessionRef session = _service->CreateSession();

	acceptEvent->Init();
	acceptEvent->sessionRef = session;
	DWORD bytes = 0;

	//Accept요청시 IOCP Queue에 전송되어 Listener Dispatch 호출
	if (false == Socket::AcceptEx(_socket, session->GetSocket(), session->_recvBuffer.Get_WriteBuffer()
		, 0, sizeof(SOCKADDR_IN) + 16, sizeof(SOCKADDR_IN) + 16, OUT & bytes, static_cast<LPOVERLAPPED>(acceptEvent)))
	{
		int16 errorcode = WSAGetLastError();
		if (errorcode != WSA_IO_PENDING)
		{
			acceptEvent->sessionRef = nullptr;
			Accept(acceptEvent);
		}
	}
}

void Listener::ProcessAccept(AcceptEvent* acceptEvent)
{
	//Server
	SessionRef session = acceptEvent->sessionRef;
	uint32 maxSession = std::static_pointer_cast<ServerService>(session->GetService())->MaxSession();
	uint32 sessionCount = std::static_pointer_cast<ServerService>(session->GetService())->GetSessionCount();

	if (sessionCount + 1 > maxSession)
	{
		GetError(OVER_SESSION);
		Accept(acceptEvent);
		return;
	}

	if (false == Socket::SetUpdateAcceptSocket(session->GetSocket(), _socket))
	{
		GetError(SET_ERROR);
		Accept(acceptEvent);
		return;
	}
	/*
	if (false == Socket::HeartBeatSocket(session->GetSocket()))
	{
		GetError(SET_ERROR);
		Accept(acceptEvent);
		return;
	}
	*/
	SOCKADDR_IN sockAddress;
	int size_address = sizeof(sockAddress);
	if (SOCKET_ERROR == getpeername(session->GetSocket(), reinterpret_cast<SOCKADDR*>(&sockAddress), &size_address))
	{
		int16 errorcode = WSAGetLastError();
		GetError(errorcode);
		Accept(acceptEvent);
		return;
	}

	session->SetNetAddress(sockAddress);
	session->StartConnect();
	std::cout << "Connected !" << std::endl;
	Accept(acceptEvent);
}

void Listener::GetError(int16 errorcode)
{
	std::cout << "Listen Error : " << errorcode << std::endl;
}

HANDLE Listener::Gethandle()
{
	if (_socket == INVALID_SOCKET)
		return nullptr;

	return reinterpret_cast<HANDLE>(_socket);
}

void Listener::Dispatch(IocpEvent* iocpEvent, uint32 Bytes)
{
	if (iocpEvent->_type != IocpType::ACCEPT)
		return;
	AcceptEvent* acceptEvent = reinterpret_cast<AcceptEvent*>(iocpEvent);
	ProcessAccept(acceptEvent);
}
