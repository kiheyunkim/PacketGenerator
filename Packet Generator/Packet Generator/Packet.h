#ifndef _PACKET_H_
#define _PACKET_H_
#include "CriticalSection.h"
#include "Protocol.h"
#include "Stream.h"
#include "Predef.h"
class PacketIO;

class Packet
{
private:
	friend class PacketIO;

private:
	CriticalSection cs;

private:
	char data[PACKET_BUFFER_SIZE];
	std::size_t dataLength;

private:
	PACKET_TYPE packetType;

private:
	bool isFull(std::size_t size)						const;
	bool isEmpty()										const;

public:
	Packet& operator+(bool boolValue);
	Packet& operator+(short shortValue);
	Packet& operator+(int intValue);
	Packet& operator+(float floatValue);
	Packet& operator+(char charValue);
	Packet& operator+(const char* string);

public:
	Packet& operator+=(bool boolValue);
	Packet& operator+=(short shortValue);
	Packet& operator+=(int intValue);
	Packet& operator+=(float floatValue);
	Packet& operator+=(char charValue);
	Packet& operator+=(const char* string);

public:
	Packet& operator-(bool& boolValue);
	Packet& operator-(short& shortValue);
	Packet& operator-(int& intValue);
	Packet& operator-(float& floatValue);
	Packet& operator-(char& charValue);
	Packet& operator-(char* string);

public:
	Packet& operator-=(bool& boolValue);
	Packet& operator-=(short& shortValue);
	Packet& operator-=(int& intValue);
	Packet& operator-=(float& floatValue);
	Packet& operator-=(char& charValue);
	Packet& operator-=(char* string);

public:
	Packet();
	Packet(PACKET_TYPE packetType);
	~Packet();

public:
	PACKET_TYPE GetPacketType()							const;
	void SetPacketType(PACKET_TYPE packetType);

public:
	virtual bool SetDataToStream(Stream& stream);
	virtual bool GetDataFromStream(Stream& stream, std::size_t length);
};

#endif // !_PACKET_H_
