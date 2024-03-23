#pragma once

struct MemoryHeader
{
	MemoryHeader(int32 size) : _allocSize(size) {}

	static void* AttachHeader(MemoryHeader* header, int32 size)
	{
		new(header)MemoryHeader(size);
		return reinterpret_cast<void*>(++header);
	}

	static MemoryHeader* DeachHeader(void* ptr)
	{
		return reinterpret_cast<MemoryHeader*>(ptr) - 1;
	}

	int32 _allocSize;
};

//
//	MemoryPool
//
class MemoryPool 
{
public:
	MemoryPool(int32 allocSize);
	~MemoryPool();

	void Push(MemoryHeader* ptr);
	MemoryHeader* Pop();
	
private:
	int32 _allocSize = 0;
	Atomic<int32> _allocCount = 0;

	Mutex _lock;
	std::queue<MemoryHeader*> _queue;
};


//
//	Memory
//
class Memory
{
	enum
	{
		POOL_COUNT = (1024 / 32) + (1024 / 128) + (2048 / 256),
		MAX_ALLOC_SIZE = 4096,
	};

public:
	Memory();
	~Memory();

	void* Allocate(int32 size);
	void Release(void* ptr);

private:
	std::vector<MemoryPool*> _pools;

	MemoryPool* _poolTable[MAX_ALLOC_SIZE + 1];
};

