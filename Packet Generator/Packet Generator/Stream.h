#ifndef _STREAM_H_
#define _STREAM_H_
#include "Predef.h"
#include "CriticalSection.h"

class Packet;
class Stream
{
private:
	friend class Packet;

private:
	CriticalSection cs;

private:
	std::size_t streamLength;
	char streamData[STREAM_BUFFER_SIZE];

private:
	void SetStreamLength(std::size_t length);
	void RemoveSendedLength(std::size_t length);

public:
	Stream();
	~Stream();

public:
	char* GetStream();
	std::size_t GetStreamLength();

public:
};

#endif // !_STREAM_H_
