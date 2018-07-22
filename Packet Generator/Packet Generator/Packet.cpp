#include "stdafx.h"
#include "Predef.h"
#include "PacketIO.h"
#include "Packet.h"

bool Packet::isFull(std::size_t size) const { return dataLength + size > PACKET_BUFFER_SIZE; }

bool Packet::isEmpty() const { return dataLength == 0; }

Packet::Packet() :dataLength(0)
{
	memset(data, 0, PACKET_BUFFER_SIZE);
}


Packet::Packet(PACKET_TYPE packetType)
	: packetType(packetType), dataLength(0)
{
	memset(data, 0, PACKET_BUFFER_SIZE);
}

Packet::~Packet() {}

//Packet Write
Packet& Packet::operator+(bool boolValue)
{
	CriticalSectionSync sync(cs);

	PacketIO packetIO;
	packetIO.WriteBool(this, boolValue);

	return *this;
}

Packet& Packet::operator+(short shortValue)
{
	CriticalSectionSync sync(cs);

	PacketIO packetIO;
	packetIO.WriteShort(this, shortValue);

	return *this;
}

Packet& Packet::operator+(int intValue)
{
	CriticalSectionSync sync(cs);

	PacketIO packetIO;
	packetIO.WriteInt(this, intValue);

	return *this;
}

Packet& Packet::operator+(float floatValue)
{
	CriticalSectionSync sync(cs);

	PacketIO packetIO;
	packetIO.WriteFloat(this, floatValue);

	return *this;
}

Packet& Packet::operator+(char charValue)
{
	CriticalSectionSync sync(cs);

	PacketIO packetIO;
	packetIO.WriteChar(this, charValue);

	return *this;
}

Packet& Packet::operator+(const char* string)
{
	CriticalSectionSync sync(cs);

	PacketIO packetIO;
	int writeLength = static_cast<int>(strlen(string));
	packetIO.WriteString(this, string, writeLength);
	packetIO.WriteInt(this, writeLength);

	return *this;
}

Packet& Packet::operator+=(bool boolValue)
{
	CriticalSectionSync sync(cs);

	PacketIO packetIO;
	packetIO.WriteBool(this, boolValue);

	return *this;
}

Packet& Packet::operator+=(short shortValue)
{
	CriticalSectionSync sync(cs);

	PacketIO packetIO;
	packetIO.WriteShort(this, shortValue);

	return *this;
}

Packet& Packet::operator+=(int intValue)
{
	CriticalSectionSync sync(cs);

	PacketIO packetIO;
	packetIO.WriteInt(this, intValue);

	return *this;
}

Packet& Packet::operator+=(float floatValue)
{
	CriticalSectionSync sync(cs);

	PacketIO packetIO;
	packetIO.WriteFloat(this, floatValue);

	return *this;
}

Packet& Packet::operator+=(char charValue)
{
	CriticalSectionSync sync(cs);

	PacketIO packetIO;
	packetIO.WriteChar(this, charValue);

	return *this;
}

Packet& Packet::operator+=(const char* string)
{
	CriticalSectionSync sync(cs);

	PacketIO packetIO;
	int writeLength = static_cast<int>(strlen(string));
	packetIO.WriteString(this, string, writeLength);
	packetIO.WriteInt(this, writeLength);

	return *this;
}

//Packet Read
Packet& Packet::operator-(bool& boolValue)
{
	CriticalSectionSync sync(cs);

	PacketIO packetIO;
	packetIO.ReadBool(this, boolValue);

	return *this;
}

Packet& Packet::operator-(short& shortValue)
{
	CriticalSectionSync sync(cs);

	PacketIO packetIO;
	packetIO.ReadShort(this, shortValue);

	return *this;
}

Packet& Packet::operator-(int& intValue)
{
	CriticalSectionSync sync(cs);

	PacketIO packetIO;
	packetIO.ReadInt(this, intValue);

	return *this;
}

Packet& Packet::operator-(float& floatValue)
{
	CriticalSectionSync sync(cs);

	PacketIO packetIO;
	packetIO.ReadFloat(this, floatValue);

	return *this;
}

Packet& Packet::operator-(char& charValue)
{
	CriticalSectionSync sync(cs);

	PacketIO packetIO;
	packetIO.ReadChar(this, charValue);

	return *this;
}

Packet& Packet::operator-(char* string)
{
	CriticalSectionSync sync(cs);

	PacketIO packetIO;

	int readLength{ 0 };
	packetIO.ReadInt(this, readLength);
	packetIO.ReadString(this, string, readLength);

	return *this;
}

Packet& Packet::operator-=(bool& boolValue)
{
	CriticalSectionSync sync(cs);

	PacketIO packetIO;
	packetIO.ReadBool(this, boolValue);

	return *this;
}

Packet& Packet::operator-=(short& shortValue)
{
	CriticalSectionSync sync(cs);

	PacketIO packetIO;
	packetIO.ReadShort(this, shortValue);

	return *this;
}

Packet& Packet::operator-=(int& intValue)
{
	CriticalSectionSync sync(cs);

	PacketIO packetIO;
	packetIO.ReadInt(this, intValue);

	return *this;
}

Packet& Packet::operator-=(float& floatValue)
{
	CriticalSectionSync sync(cs);

	PacketIO packetIO;
	packetIO.ReadFloat(this, floatValue);

	return *this;
}

Packet& Packet::operator-=(char& charValue)
{
	CriticalSectionSync sync(cs);

	PacketIO packetIO;
	packetIO.ReadChar(this, charValue);

	return *this;
}

Packet& Packet::operator-=(char* string)
{
	CriticalSectionSync sync(cs);

	PacketIO packetIO;

	int readLength{ 0 };
	packetIO.ReadInt(this, readLength);
	packetIO.ReadString(this, string, readLength);

	return *this;
}


PACKET_TYPE Packet::GetPacketType() const { return packetType; }

void Packet::SetPacketType(PACKET_TYPE packet)
{
	CriticalSectionSync sync(cs);

	packetType = packet;
}

bool Packet::SetDataToStream(Stream& stream)
{
	CriticalSectionSync sync(cs);

	memcpy(stream.GetStream(), reinterpret_cast<void*>(&packetType), sizeof(PACKET_TYPE));
	memcpy(stream.GetStream() + sizeof(PACKET_TYPE), data, dataLength);

	stream.SetStreamLength(dataLength + sizeof(PACKET_TYPE));

	return true;
}

bool Packet::GetDataFromStream(Stream& stream, std::size_t length)
{
	CriticalSectionSync sync(cs);

	int type{ 0 };
	memcpy(&type, stream.GetStream(), sizeof(PACKET_TYPE));
	packetType = static_cast<PACKET_TYPE>(type);

	memcpy(data, stream.GetStream() + sizeof(PACKET_TYPE), length - sizeof(PACKET_TYPE));
	dataLength = length - sizeof(PACKET_TYPE);

	return true;
}