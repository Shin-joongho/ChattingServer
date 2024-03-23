#include "pch.h"
#include "NetAddress.h"

NetAddress::NetAddress(std::wstring ip, uint16 port)
{
	memset(&_sockaddr, 0, sizeof(_sockaddr));
	_sockaddr.sin_family = AF_INET;
	_sockaddr.sin_addr = Ip2Address(ip.c_str());
	_sockaddr.sin_port = ::htons(port);
}

std::wstring NetAddress::GetIpAddress()
{
	const uint16 bufferSize = 100;
	WCHAR buffer[bufferSize];
	::InetNtopW(AF_INET, &_sockaddr.sin_addr, buffer, bufferSize);
	return std::wstring(buffer);
}

IN_ADDR NetAddress::Ip2Address(const WCHAR* ip)
{
	IN_ADDR address;
	::InetPtonW(AF_INET, ip, &address);
	return address;
}
