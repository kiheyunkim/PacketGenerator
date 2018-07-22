#ifndef _PACKETIO_H_
#define _PACKETIO_H_
#include "CriticalSection.h"
///PacketIO Class 
///this class is used for write data in Packet class
class Packet;
class PacketIO
{
private:
	CriticalSection cs;

public:
	bool WriteBool(Packet* packet, bool boolValue);
	bool WriteShort(Packet* packet, short shortValue);
	bool WriteInt(Packet* packet, int intValue);
	bool WriteFloat(Packet* packet, float floatValue);
	bool WriteChar(Packet* packet, char charValue);
	bool WriteString(Packet* packet, const char* str, std::size_t strLength);

public:
	bool ReadBool(Packet* packet, bool& boolValue);
	bool ReadShort(Packet* packet, short& shortValue);
	bool ReadInt(Packet* packet, int& intValue);
	bool ReadFloat(Packet* packet, float& floatValue);
	bool ReadChar(Packet* packet, char& charValue);
	bool ReadString(Packet* packet, char* str, std::size_t strLength);
};

#endif // !_PACKETIO_H_