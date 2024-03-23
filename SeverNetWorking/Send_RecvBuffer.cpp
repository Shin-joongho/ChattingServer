#include "pch.h"
#include "Send_RecvBuffer.h"

SendBuffer::SendBuffer()
{
	_buffer = (char*)malloc(PACKET_SIZE); //���� ������ ����
	memset(_buffer, 0, PACKET_SIZE); 
}

bool SendBuffer::CopyData(Packet_Type _type, Protocol::BuffData data)
{
	uint16 len = data.ByteSizeLong();
	_packet._type = _type;
	_packet._size = len;

	memcpy(_buffer, reinterpret_cast<char*>(&_packet), ID_SIZE); //PacketID �߰�
	if (data.SerializeToArray(_buffer + ID_SIZE, len) == false) //ProtoBuf�� PacketID �ڿ� �߰�
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

bool SendBuffer::CopyData(RecvBuffer recvBuffer) //�������� ���� ��Ŷ�� BroadCast�Ҷ� ���
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
	if (_overflow == false || bytes >= ID_SIZE) // ��� ũ�⸸ŭ ������ ���� ��� ���� �����͸� �ޱ����� �Ѿ
	{
		Packet_ID* p = reinterpret_cast<Packet_ID*>(Get_ReadBuffer());
		_packet = *p;
	}

	write_pos += bytes;		
	//���� �����Ϳ� ���ľ��ϰų� ��� ũ�⸸ŭ ������ ���� ���
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
	if (IsData()) //���� �����Ϳ� ����Ǿ�� �ϱ⿡ �տ� read pos�� write pos�� ������ �ű�� �����͸� ����
	{
		int size = write_pos - read_pos;
		memcpy(&_buffer[0], &_buffer[read_pos], size);
		read_pos = 0;
		write_pos = size;
	}
	else //read pos�� write pos�� ���⿡ �����Ͱ� ���� ������ �����Ͽ� ��ġ ����
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

