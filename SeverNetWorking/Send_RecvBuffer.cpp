#include "pch.h"
#include "Send_RecvBuffer.h"

SendBuffer::SendBuffer()
{
	_buffer = (char*)malloc(PACKET_SIZE); //버퍼 사이즈 설정
	memset(_buffer, 0, PACKET_SIZE); 
}

bool SendBuffer::CopyData(Packet_Type _type, Protocol::BuffData data)
{
	uint16 len = data.ByteSizeLong();
	_packet._type = _type;
	_packet._size = len;

	memcpy(_buffer, reinterpret_cast<char*>(&_packet), ID_SIZE); //PacketID 추가
	if (data.SerializeToArray(_buffer + ID_SIZE, len) == false) //ProtoBuf를 PacketID 뒤에 추가
		return false;

	return true;
}

bool SendBuffer::CopyData(Protocol::Login login)
{
	uint16 len = login.ByteSizeLong();
	_packet._type = Packet_Type::LOGIN;
	_packet._size = len;

	memcpy(_buffer, reinterpret_cast<char*>(&_packet), ID_SIZE);
	login.SerializeToArray(_buffer + ID_SIZE, len);

	return true;
}

bool SendBuffer::CopyData(RecvBuffer recvBuffer) //서버에서 받은 패킷을 BroadCast할때 사용
{
	_packet = recvBuffer.GetPacket_ID();
	memcpy(_buffer, recvBuffer.Get_ReadBuffer(), recvBuffer.GetSize() + ID_SIZE);
	return true;
}

RecvBuffer::RecvBuffer()
{
	_buffer.resize(PACKET_SIZE);
}

bool RecvBuffer::Div_Buffer(int32 bytes)
{
	if (_overflow == false || bytes >= ID_SIZE) // 헤더 크기만큼 들어오지 않을 경우 다음 데이터를 받기위해 넘어감
	{
		Packet_ID* p = reinterpret_cast<Packet_ID*>(Get_ReadBuffer());
		_packet = *p;
	}

	write_pos += bytes;		
	//이전 데이터와 합쳐야하거나 헤더 크기만큼 들어오지 않을 경우
	if ((bytes < ID_SIZE || _packet._size + ID_SIZE > bytes) && _overflow == false) 
	{
		Clear();
		_overflow = true;
		return false;
	}
	else
		_overflow = false;
	
	return true;
}

void RecvBuffer::Set_ReadPos(uint16 bytes)
{
	if(IsData() == false)
		read_pos = 0;
	else
		read_pos += bytes;
}

void RecvBuffer::Clear()
{
	if (IsData()) //이전 데이터와 연결되어야 하기에 앞에 read pos와 write pos를 앞으로 옮기고 데이터를 복사
	{
		int size = write_pos - read_pos;
		memcpy(&_buffer[0], &_buffer[read_pos], size);
		read_pos = 0;
		write_pos = size;
	}
	else //read pos와 write pos가 같기에 데이터가 없는 것으로 판정하여 위치 조정
	{
		write_pos = 0;
		read_pos = 0;
		_packet._type = Packet_Type::P_NULL;
		_packet._size = 0;
	}
}

void RecvBuffer::GetError(int16 errorcode)
{
	std::cout << "RecvBUffer Error : " << errorcode << std::endl;
}

