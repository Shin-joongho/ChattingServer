#include "pch.h"
#include "MemoryPool.h"

//
//	MemoryPool
//

MemoryPool::MemoryPool(int32 allocSize) : _allocSize(allocSize)
{
}

MemoryPool::~MemoryPool()
{
	while (_queue.empty() == false)
	{
		MemoryHeader* header = _queue.front();
		_queue.pop();
		free(header);
	}
}

void MemoryPool::Push(MemoryHeader* ptr)
{
	{
		LockGuard lg(_lock); // lockguard 동기화
		ptr->_allocSize = 0;

		_queue.push(ptr);
	}
	
	_allocCount.fetch_sub(1);
}

MemoryHeader* MemoryPool::Pop()
{
	MemoryHeader* header = nullptr;

	{
		LockGuard lg(_lock);  // lockguard 동기화

		if (_queue.empty() == false)
		{
			header = _queue.front();
			_queue.pop();
		}
	}

	if (header == nullptr)
	{
		header = reinterpret_cast<MemoryHeader*>(malloc(_allocSize));
	}

	_allocCount.fetch_add(1);

	return header;
}

//
//	Memory
//

Memory::Memory()
{
	int32 size = 0;
	int32 tableIndex = 0;

	for (size = 32; size <= 1024; size += 32)
	{
		MemoryPool* pool = new MemoryPool(size);
		_pools.push_back(pool);

		while (tableIndex <= size)
		{
			_poolTable[tableIndex] = pool;
			tableIndex++;
		}
	}

	for (size = 1024; size <= 2048; size += 128)
	{
		MemoryPool* pool = new MemoryPool(size);
		_pools.push_back(pool);

		while (tableIndex <= size)
		{
			_poolTable[tableIndex] = pool;
			tableIndex++;
		}
	}

	for (size = 2048; size <= 4096; size += 256)
	{
		MemoryPool* pool = new MemoryPool(size);
		_pools.push_back(pool);

		while (tableIndex <= size)
		{
			_poolTable[tableIndex] = pool;
			tableIndex++;
		}
	}
}

Memory::~Memory()
{
	for (MemoryPool* pool : _pools)
		delete pool;

	_pools.clear();
}

void* Memory::Allocate(int32 size)
{
	MemoryHeader* header = nullptr;
	int allocSize = size + sizeof(MemoryHeader); // memory header + data size

	if (size > MAX_ALLOC_SIZE)
	{
		header = reinterpret_cast<MemoryHeader*>(malloc(size));
	}
	else
	{
		header = _poolTable[size]->Pop();
	}

	return header;
}

void Memory::Release(void* ptr)
{
	MemoryHeader* header = MemoryHeader::DeachHeader(ptr);
	
	if (header->_allocSize > MAX_ALLOC_SIZE)
	{
		free(ptr);
	}
	else
	{
		_poolTable[header->_allocSize]->Push(header);
	}
}
