#pragma once
#include "IocpEvent.h"

class IOCP_Object : public std::enable_shared_from_this<IOCP_Object>
{
public:
	virtual HANDLE Gethandle() abstract;
	virtual void Dispatch(class IocpEvent*, uint32 bytes) abstract;
};

class IOCP
{
public:
	IOCP();
	~IOCP();

	HANDLE GetHandle() { return _handle; }
	//IOCP µî·Ï
	bool Register(IOCP_ObjectRef iocp_object);
	//IOCP QUEUE
	bool Dispatch();
	
private:
	HANDLE _handle;
};

