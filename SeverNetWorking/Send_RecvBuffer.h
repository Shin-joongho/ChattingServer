#pragma once
#include "Protocol.pb.h"
enum class Packet_Type : uint16
{
	P_NULL = 0,
	LOGIN = 1000,
	BROADCAST,
	DM,
};

struct Packet_ID
{
	Packet_Type _type;
	uint16 _size;
};

const int16 PACKET_SIZE = 1024;
const int16 ID_SIZE = sizeof(Packet_ID);

class SendBuffer : public std::enable_shared_from_this<SendBuffer>
{
public:
	SendBuffer();

	bool CopyData(Packet_Type _type, Protocol::BuffData data);
	bool CopyData(Protocol::Login login);
	bool CopyData(class RecvBuffer recvBuffer);
	uint16 GetSize() { return _packet._size + ID_SIZE; }
	char* GetBuffer() { return _buffer; }

private:
	char* _buffer = nullptr;
	Packet_ID _packet;
};


class RecvBuffer
{
public:
	RecvBuffer();

	bool Div_Buffer(int32 bytes); //데이터 확인을 위해 가장 먼저 실행

	char* Get_WriteBuffer() { return &_buffer[write_pos]; }
	char* Get_ReadBuffer() { return &_buffer[read_pos]; }
	char* Get_ReadData() { return &_buffer[read_pos + ID_SIZE]; }

	bool IsData() { return write_pos - read_pos != 0; }
	Packet_Type GetType() { return _packet._type; }
	uint16 GetSize() { return _packet._size; }
	uint16 GetBufferSize() { return _packet._size + ID_SIZE; }
	Packet_ID GetPacket_ID() { return _packet; }
	void Set_ReadPos(uint16 bytes);

	uint16 PacketSize() { return PACKET_SIZE - write_pos; }
	
	void Clear();
	void GetError(int16 errorcode);

private:
	uint16 write_pos = 0;
	uint16 read_pos = 0;
	std::vector<char> _buffer;
	Packet_ID _packet;
	bool _overflow = false;
};
