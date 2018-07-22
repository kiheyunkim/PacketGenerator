#include "stdafx.h"
#include "Packet.h"
#include "Stream.h"
#include "Predef.h"

Stream::Stream() :streamLength(0) { memset(streamData, 0, STREAM_BUFFER_SIZE); }

Stream::~Stream() {}

char* Stream::GetStream()
{
	CriticalSectionSync sync(cs);

	return streamData;
}

std::size_t Stream::GetStreamLength()
{
	CriticalSectionSync sync(cs);

	return streamLength;
}

void Stream::SetStreamLength(std::size_t length)
{
	CriticalSectionSync sync(cs);

	streamLength = length;
};

void Stream::RemoveSendedLength(std::size_t length)
{
	CriticalSectionSync sync(cs);

	streamLength -= length;
	//PullRemainedData(length);
}
