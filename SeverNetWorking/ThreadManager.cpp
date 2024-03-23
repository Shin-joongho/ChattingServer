#include "pch.h"
#include "ThreadManager.h"
#include "Thread_M.h"

Atomic<uint16> ThreadManager::_threadID = 0;

ThreadManager::ThreadManager()
{
	InitTLS();
}

ThreadManager::~ThreadManager()
{

}

void ThreadManager::Start(std::function<void(void)> callback)
{
	LockGuard lockguard(_mutex);

	_threads.push_back(std::thread([=]()
		{
			InitTLS();
			callback();
		}));
}

void ThreadManager::Join()
{
	for (std::thread& t : _threads)
	{
		if (t.joinable())
			t.join();
	}
	_threads.clear();
}

void ThreadManager::InitTLS()
{
	ThreadID = _threadID.fetch_add(1);
}
