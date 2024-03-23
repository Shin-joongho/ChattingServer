#pragma once
#include "IOCP.h"
#include "NetAddress.h"
#include "Listener.h"
#include "Session.h"
#include <set>
#include <map>
#include <functional>
#include "protocol.pb.h"
#include "Send_RecvBuffer.h"
#include "MySQL_DB.h"
#include "Send_Time.h"

enum class ServiceType
{
	SERVER,
	CLIENT
};

using SessionFac = std::function<SessionRef(void)>;

class Service : public std::enable_shared_from_this<Service>
{
public:
	Service(ServiceType type, NetAddress netaddress, IOCPRef iocpRef, SessionFac _sessionFac, uint32 maxSession);
	virtual ~Service() {};

	virtual bool Start() abstract;
	bool CanStart() { return _sessionFac != nullptr; }

	//Server Service
	virtual void AddNmToSession(SessionRef session, std::string name) {}
	virtual void RlsNmToSession(SessionRef session, std::string name) {}
	virtual bool SendToOneSession(SendBufferRef sendbuffer, std::string nickName);

	//IOCP
	SessionRef CreateSession();

	//sessions
	virtual void AddSession(SessionRef session); //Client override
	virtual void ReleaseSession(SessionRef session); //Client override

	//Set Get
	NetAddress GetNetAddress() { return _netaddress; }
	IOCPRef GetIOCP() { return _iocpRef; }
	ServiceType GetServiceType() { return _type; }

	//Error
	void GetError(int errorcode);

protected:
	Mutex _lock;
	ServiceType _type;
	IOCPRef _iocpRef;
	NetAddress _netaddress;

	std::set<SessionRef> _sessions;
	uint32 _maxSession; //최대 Session수 //Client Service시 Client생성 갯수
	Atomic<uint32> _sessionCount = 0; //현재 Session수
	SessionFac _sessionFac; //서비스할 Session

	MySQL_DB mysql;
};

class ServerService : public Service
{
public:
	ServerService(NetAddress netaddress, IOCPRef iocpRef, SessionFac sessionFac, uint32 maxSession);
	virtual ~ServerService() { mysql.Close(); };

	virtual bool Start() override;
	virtual void AddNmToSession(SessionRef session, std::string name);
	virtual void RlsNmToSession(SessionRef session, std::string name);
	virtual bool SendToOneSession(SendBufferRef sendbuffer, std::string nickName) override;

	uint32 MaxSession() { return _maxSession; }
	uint32 GetSessionCount() { return _sessionCount; }
	uint32 SetSessionCount() { _sessionCount.fetch_add(1); }
	uint32 GetNmToSessionCount() { return _nmToSession.size(); }

public:
	void BroadCast(SendBufferRef sendbuffer);
	void BroadCast(SendBufferRef sendbuffer, SessionRef send_session);
	bool DirectMessage(SendBufferRef sendbuffer) {};
	SessionRef FindNmToSession(std::string findName);

	//DB
	bool SaveLog(std::string nickName, std::string log);

private:
	Mutex _mapLock;
	ListenerRef _listener = nullptr;
	std::map<std::string, SessionRef> _nmToSession;
};

class ClientService : public Service
{
public:
	//한번에 다수
	ClientService(NetAddress netaddress, IOCPRef iocpRef, SessionFac sessionFac, uint32 maxSession);
	//실제 사용할 한번에 한 계정
	ClientService(NetAddress netaddress, IOCPRef iocpRef, SessionFac sessionFac);
	virtual ~ClientService() {};

	virtual bool Start() override;
	virtual void AddSession(SessionRef session) override;
	virtual void ReleaseSession(SessionRef session) override;

	//DB
	std::pair<bool, std::string> Login_Accept();

public:
	std::vector<std::string> Msg_Split(std::string msg, char delimiter);
	bool Client_Send(std::string msg);

private:
	void GetError(int16 errorcode);

private:
	SessionRef _userSession;
};
