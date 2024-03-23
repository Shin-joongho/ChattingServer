#pragma once

class PoolAlloc
{
public:
	static void* Alloc(int32 size);
	static void Release(void* ptr);
};

template<typename Type, typename... Args>
Type* xnew(Args&&... args)
{
	Type* memory = static_cast<Type*>(xmalloc(sizeof(Type)));
	new(memory)Type(std::forward<Args>(args)...);
	return memory;
}

template<typename Type>
void xdelete(Type* obj)
{
	obj->~Type();
	xfree(obj);
}
