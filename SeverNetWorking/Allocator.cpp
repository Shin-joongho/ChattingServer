#include "pch.h"
#include "Allocator.h"
#include "Global_C.h"
#include "MemoryPool.h"

void* PoolAlloc::Alloc(int32 size)
{
	return GMemory->Allocate(size);
}

void PoolAlloc::Release(void* ptr)
{
	GMemory->Release(ptr);
}
