#pragma once
#include "IOCP.h"
#include "IocpEvent.h"
#include "Socket.h"
#include "NetAddress.h"
#include "Service.h"

class Listener : public IOCP_Object
{
public:
	Listener() {};
	~Listener();

public:
	bool Init(ServerServiceRef service);
	void Accept(AcceptEvent* acceptEvent);
	void ProcessAccept(AcceptEvent* acceptEvent);

	void GetError(int16 errorcode);

	virtual HANDLE Gethandle() override;
	virtual void Dispatch(IocpEvent* iocpEvent, uint32 Bytes) override;

private:
	SOCKET _socket = INVALID_SOCKET;
	std::vector<AcceptEvent*> _acceptEvents;
	ServerServiceRef _service;
};

