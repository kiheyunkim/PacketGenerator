#include "stdafx.h"
#include "Stream.h"
#include "Packet.h"
#include "PacketIO.h"

bool PacketIO::WriteBool(Packet* packet, bool boolValue)
{
	CriticalSectionSync sync(cs);

	if (packet == nullptr) return false;
	if (packet->isFull(sizeof(bool))) return false;

	memcpy(packet->data + packet->dataLength, &boolValue, sizeof(bool));
	packet->dataLength += sizeof(bool);

	return true;
}

bool PacketIO::WriteShort(Packet* packet, short shortValue)
{
	CriticalSectionSync sync(cs);

	if (packet == nullptr) return false;
	if (packet->isFull(sizeof(short))) return false;

	memcpy(packet->data + packet->dataLength, &shortValue, sizeof(short));
	packet->dataLength += sizeof(short);

	return true;
}

bool PacketIO::WriteInt(Packet* packet, int intValue)
{
	CriticalSectionSync sync(cs);

	if (packet == nullptr) return false;
	if (packet->isFull(sizeof(int))) return false;

	memcpy(packet->data + packet->dataLength, &intValue, sizeof(int));
	packet->dataLength += sizeof(int);

	return true;
}

bool PacketIO::WriteFloat(Packet* packet, float floatValue)
{
	CriticalSectionSync sync(cs);

	if (packet == nullptr) return false;
	if (packet->isFull(sizeof(float))) return false;

	memcpy(packet->data + packet->dataLength, &floatValue, sizeof(float));
	packet->dataLength += sizeof(float);

	return true;
}

bool PacketIO::WriteChar(Packet* packet, char charValue)
{
	CriticalSectionSync sync(cs);

	if (packet == nullptr) return false;
	if (packet->isFull(sizeof(charValue))) return false;

	memcpy(packet->data + packet->dataLength, &charValue, sizeof(char));
	packet->dataLength += sizeof(char);

	return true;
}

bool PacketIO::WriteString(Packet* packet, const char* str, std::size_t strLength)
{
	CriticalSectionSync sync(cs);

	if (packet == nullptr) return false;
	if (packet->isFull(strLength)) return false;

	memcpy(packet->data + packet->dataLength, str, strLength);
	packet->dataLength += strLength;

	return true;
}

bool PacketIO::ReadBool(Packet* packet, bool& boolValue)
{
	CriticalSectionSync sync(cs);

	if (packet == nullptr) return false;
	if (packet->isEmpty()) return false;

	memcpy(&boolValue, packet->data + packet->dataLength - sizeof(bool), sizeof(bool));
	packet->dataLength -= sizeof(bool);

	return true;
}

bool PacketIO::ReadShort(Packet* packet, short& shortValue)
{
	CriticalSectionSync sync(cs);

	if (packet == nullptr) return false;
	if (packet->isEmpty()) return false;

	memcpy(&shortValue, packet->data + packet->dataLength - sizeof(short), sizeof(short));
	packet->dataLength -= sizeof(short);

	return true;
}

bool PacketIO::ReadInt(Packet* packet, int& intValue)
{
	CriticalSectionSync sync(cs);

	if (packet == nullptr) return false;
	if (packet->isEmpty()) return false;

	memcpy(&intValue, packet->data + packet->dataLength - sizeof(int), sizeof(int));
	packet->dataLength -= sizeof(int);
	 
	return true;
}

bool PacketIO::ReadFloat(Packet* packet, float& floatValue)
{
	CriticalSectionSync sync(cs);

	if (packet == nullptr) return false;
	if (packet->isEmpty()) return false;

	memcpy(&floatValue, packet->data + packet->dataLength - sizeof(float), sizeof(float));
	packet->dataLength -= sizeof(float);

	return true;
}

bool PacketIO::ReadChar(Packet* packet, char& charValue)
{
	CriticalSectionSync sync(cs);

	if (packet == nullptr) return false;
	if (packet->isEmpty()) return false;

	memcpy(&charValue, packet->data + packet->dataLength - sizeof(char), sizeof(char));
	packet->dataLength -= sizeof(char);

	return true;
}

bool PacketIO::ReadString(Packet* packet, char* str, std::size_t strLength)
{
	CriticalSectionSync sync(cs);

	if (packet == nullptr) return false;
	if (packet->isEmpty()) return false;

	memcpy(str, packet->data + packet->dataLength - strLength, strLength);
	packet->dataLength -= strLength;

	str[strLength] = '\0';

	return true;
}