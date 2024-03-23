#include "pch.h"
#include "Global_C.h"
#include "ThreadManager.h"
#include "Service.h"
#include "Server_Session.h"
#include "Client_Session.h"
using namespace std;

void Server()
{
	ServerServiceRef serverService = std::make_shared<ServerService>
		(NetAddress(L"127.0.0.1", 7777)
			, std::make_shared<IOCP>()
			, std::make_shared<MainServer>
			, 5);


	if (!serverService->Start())
		ServerThread->Join();

	for (int32 i = 0; i < 5; i++)
	{
		ServerThread->Start([=]()
			{
				while (true)
				{
					serverService->GetIOCP()->Dispatch();
				}
			});
	}

	ServerThread->Join();

}

void Client()
{
	ClientServiceRef client = std::make_shared<ClientService>
		(NetAddress(L"127.0.0.1", 7777)
			, std::make_shared<IOCP>()
			, std::make_shared<MainClient>);

	if (!client->Start())
		ClientThread->Join();

	for (int32 i = 0; i < 5; i++)
	{
		ClientThread->Start([=]()
			{
				while (true)
				{
					client->GetIOCP()->Dispatch();
				}
			});
	}

	std::string message;
	while (true)
	{
		std::getline(cin, message);

		if (message == "")
			continue;
		client->Client_Send(message);

		message.clear();
	}
	ClientThread->Join();
}

//protobuf 3.17 version
int main()
{
	//thread t1(Server);
	thread t2(Client);


	if (t2.joinable())
		t2.join();

	//if(t1.joinable())
	//	t1.join();

}

