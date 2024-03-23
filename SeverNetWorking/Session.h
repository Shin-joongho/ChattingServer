#pragma once

#include "IOCP.h"
#include "NetAddress.h"
#include "Service.h"
#include "Socket.h"
#include <memory>
#include "Send_RecvBuffer.h"

class Session : public IOCP_Object
{
	friend class Service;
	friend class IOCP;
	friend class Listener;

public:
	Session();
	virtual ~Session();

	//IOCP_Object override
	virtual HANDLE Gethandle() override;
	virtual void Dispatch(class IocpEvent* iocpEvent, uint32 bytes) override;

public:
	//내부정보
	SOCKET GetSocket() { return _socket; }
	void SetNetAddress(NetAddress netaddress) { _netaddress = netaddress; }
	NetAddress GetNetAddress() { return _netaddress; }
	bool IsConnect() { return _isconnect; }

	void SetService(std::shared_ptr<class Service> service) { _service = service; }
	std::shared_ptr<class Service> GetService() { return _service.lock(); }
	SessionRef GetSession() { return std::static_pointer_cast<Session>(shared_from_this()); }
	std::string GetNickName() { return _nickName; }
	void SetNickName(std::string nickName) { _nickName = nickName; }

	//Error
	void GetError(int16 errorcode);

	//encoding
	std::string UTF8_to_String(const char* utf8);
	std::string String_to_UTF8(std::string str);

public:
	bool BeforeConnect();
	void StartConnect();
	virtual void Child_Connect() {};

	void StartRecv();
	void Recv(int32 bytes);
	virtual void Child_Recv(int32 bytes) {};

	void BeforeSend(SendBufferRef sender); // 보낼 내용 buffer정리
	void StartSend();
	void Send(int32 bytes);
	virtual void Child_Send() {};

	void StartClose();
	void SessionClose();
	void Disconnect();
	virtual void Child_Close() {};

private:
	Mutex _mutex;
	SOCKET _socket = INVALID_SOCKET;
	NetAddress _netaddress = {};
	Atomic<bool> _isconnect = false;
	std::weak_ptr<class Service> _service;

protected:
	RecvBuffer _recvBuffer;
	std::queue<SendBufferRef> _sendQueue;
	Atomic<bool> _isSend = false;
	std::string _nickName = "UNKNOWN"; //Key

public:
	//overlapped event 
	ConnectEvent _connectEvent;
	DisConnectEvent _disconnectEvent;
	RecvEvent _recvEvent;
	SendEvent _sendEvent;
};

