#pragma once
#include <thread>
#include <functional>

class ThreadManager
{
public:
	ThreadManager();
	~ThreadManager();

	void Start(std::function<void(void)> callback);
	void Join();

	static void InitTLS();

	static Atomic<uint16> _threadID;

private:
	Mutex _mutex;
	std::vector<std::thread> _threads;
};

