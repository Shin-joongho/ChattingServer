#pragma once
#pragma comment(lib, "ws2_32")
#pragma comment(lib, "libmySQL.lib")

#ifdef _DEBUG
#pragma comment(lib, "Protobuf\\Debug\\libprotobufd.lib")

#else
#pragma comment(lib, "Protobuf\\Release\\libprotobuf.lib")
#endif

#define xmalloc(size) PoolAlloc::Alloc(size)
#define xfree(ptr) PoolAlloc::Release(ptr)

//CryptoPP Key
#define CKEY "f4150d4a1ac5708c29e437749045a39a"
#define CIV "86afc43868fea6abd40fbf6d5ed50905"

#include <iostream>
#include <string>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <sstream>
#include <vector>
#include <mutex>
#include <atomic>
#include <memory>
#include <queue>
#include <atlstr.h>

using uchar = unsigned char;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;
using uint16 = unsigned __int16;
using uint32 = unsigned __int32;
using uint64 = unsigned __int64;

//IP , PORT
const uint16 PORT = 7777;

template<typename T>
using Atomic = std::atomic<T>;
using Mutex = std::mutex;
using LockGuard = std::lock_guard<std::mutex>;

#define LOCK_GD LockGuard

using IOCP_ObjectRef = std::shared_ptr<class IOCP_Object>;
using IOCPRef = std::shared_ptr<class IOCP>;
using SessionRef = std::shared_ptr<class Session>;
using ServerServiceRef = std::shared_ptr<class ServerService>;
using ClientServiceRef = std::shared_ptr<class ClientService>;
using ListenerRef = std::shared_ptr<class Listener>;
using SendBufferRef = std::shared_ptr<class SendBuffer>;
using RecvBufferRef = std::shared_ptr<class RecvBuffer>;

//WSALastGetError 포함해서 사용할거라 사용자 설정 에러는 마이너스로 지정
enum ErrorCode
{
	SOCKET_INVALID = -1,
	BIND_ERROR = -2,
	LISTEN_ERROR = -3,
	IOCP_FALSE = -4,
	SET_ERROR = -5,
	OVER_SESSION = -6,

	PARSE_ERROR = -7,
	PACKET_SIZE_ERROR = -8,

	SPLIT_ERROR = -9,

	DontReadINI = -10,
	DontWriteINI = -11,
	FalseConnectDB = -12,
	FalseQuery = -13,
};

//IOCP Event Type
enum class IocpType : uint16
{
	CONNECT,
	DISCONNECT,
	ACCEPT,
	RECV,
	SEND
};
