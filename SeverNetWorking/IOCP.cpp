#include "pch.h"
#include "IOCP.h"

IOCP::IOCP()
{
	//IOCP 시작
	_handle = CreateIoCompletionPort(INVALID_HANDLE_VALUE, 0, 0, 0);
}

IOCP::~IOCP()
{
	CloseHandle(_handle);
}

bool IOCP::Register(IOCP_ObjectRef iocp_object)
{
	//IOCP 등록
	return CreateIoCompletionPort(iocp_object->Gethandle(), _handle, 0, 0);
}

bool IOCP::Dispatch()
{
	DWORD timelimit = INFINITE;
	DWORD transfBytes = 0;
	IocpEvent* iocpevent = nullptr;
	ULONG_PTR key = 0;

	if (GetQueuedCompletionStatus(_handle, &transfBytes, &key, reinterpret_cast<LPOVERLAPPED*>(&iocpevent), timelimit))
	{
		iocpevent->iocpeventRef->Dispatch(iocpevent, transfBytes);
	}
	else
	{
		int32 errCode = ::WSAGetLastError();
		switch (errCode)
		{
		case WAIT_TIMEOUT:
			return false;
		default:
			IOCP_ObjectRef iocpObject = iocpevent->iocpeventRef;
			iocpObject->Dispatch(iocpevent, transfBytes);
			break;
		}
		return true;
	}
}