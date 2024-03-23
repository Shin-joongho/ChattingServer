#pragma once
#include "Send_RecvBuffer.h"
//OVERLAPPED / IocpEvent / ...

class IocpEvent : public OVERLAPPED
{
public:
	IocpEvent(IocpType type) : _type(type) { Init(); }
	void Init();

public:
	IocpType _type;
	IOCP_ObjectRef iocpeventRef;
};

class ConnectEvent : public IocpEvent
{
public:
	ConnectEvent() : IocpEvent(IocpType::CONNECT) {}
};

class DisConnectEvent : public IocpEvent
{
public:
	DisConnectEvent() : IocpEvent(IocpType::DISCONNECT) {}
};

class AcceptEvent : public IocpEvent
{
public:
	AcceptEvent() : IocpEvent(IocpType::ACCEPT) {}
	
public:
	SessionRef sessionRef = nullptr;
};

class RecvEvent : public IocpEvent
{
public:
	RecvEvent() : IocpEvent(IocpType::RECV) {}
};

class SendEvent : public IocpEvent
{
public:
	SendEvent() : IocpEvent(IocpType::SEND) {}

public:
	std::vector<SendBufferRef> _sendBuffer;
};