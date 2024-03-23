#pragma once
class NetAddress
{
public:
	NetAddress() {};
	NetAddress(SOCKADDR_IN sockaddr) : _sockaddr(sockaddr) {};
	NetAddress(std::wstring ip, uint16 port);
	~NetAddress() {};

	SOCKADDR_IN& GetSockAddr() { return _sockaddr; }
	std::wstring GetIpAddress();
	uint16 GetPort() { return ::ntohs(_sockaddr.sin_port); }

	static IN_ADDR Ip2Address(const WCHAR* ip);
private:
	SOCKADDR_IN _sockaddr = {};
};

