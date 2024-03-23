#include "Session.h"
#include "Send_RecvBuffer.h"
#include "Protocol.pb.h"

class MainClient : public Session
{
public:
	~MainClient()
	{
		std::cout << "~GameSession" << std::endl;
	}
	void Child_Connect() override;
	void Child_Recv(int32 bytes) override;
	//void Child_Send() override;
	void Child_Close() override
	{
		std::cout << "Disconnect" << std::endl;
	}

private:
	void Login_Accept();
	void B_D_Recv(Packet_Type type);
	void GetError(int16 errorcode);
	void WriteLock(std::string msg);

private:
	Mutex _writeLock;
	Atomic<bool> _IsLogin = false;
};