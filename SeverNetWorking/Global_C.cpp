#include "pch.h"
#include "Global_C.h"
#include "ThreadManager.h"
#include "Socket.h"
#include "MemoryPool.h"

ThreadManager* ServerThread = nullptr;
ThreadManager* ClientThread = nullptr;
Memory* GMemory = nullptr;

class Global
{
public:
	Global()
	{
		ServerThread = new ThreadManager();
		GMemory = new Memory();
		ClientThread = new ThreadManager();
		Socket::Socket_Init();
	}
	~Global()
	{
		delete ServerThread;
		delete GMemory;
		delete ClientThread;
		Socket::Socket_Clear();
	}
} Global_Fuc;
