// Packet Generator.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
#include "stdafx.h"
#include "Packet.h"
#include "Protocol.h"

int main()
{
	Packet packet;
	Stream stream;

	bool boolValue = false;
	short shortValue = 123;
	int integarValue = 3234;
	float floatValue = 3.04f;
	char charValue = 'z';
	const char* string = "TestString3";

	std::cout << "1. 조합 전 값들" << '\n';
	std::cout << "boolValue: " << boolValue << ", "
		<< "shortValue: " << shortValue << ", "
		<< "integarValue: " << integarValue << "\n"
		<< "floatValue: " << floatValue << ", "
		<< "charValue: " << charValue << ", "
		<< "string: " << string << '\n';

	std::cout << "\n2. + 연산자를 이용한 패킷 조합" << '\n'
		<< "packet = packet + boolValue + shortValue + integarValue \n + floatValue + charValue + string" << '\n';
	packet = packet + boolValue + shortValue + integarValue + floatValue + charValue + string;

	std::cout << "\n3. Packet -> Stream Class 변환(헤더와 패킷 통합)" << '\n';
	packet.SetPacketType(PACKET_TYPE::Test);	//Packet Type 구분용
	packet.SetDataToStream(stream);

	std::cout << "\n4. Packet 조합 후 Stream 내용" << '\n';
	std::cout << stream.GetStream() << '\n';

	Packet packet2;
	Stream stream2;
	std::cout << "\n5. (전송 가정) Stream -> Stream2 class 복사" << std::endl;
	stream2 = stream;

	std::cout << "\n6. Stream2 분해 전 내용" << '\n';
	std::cout << stream2.GetStream() << '\n';

	std::cout << "\n7. Stream2 -> Packet2 Class 변환(헤더와 패킷 분리)" << '\n';
	packet2.GetDataFromStream(stream2, stream.GetStreamLength());
	std::cout << static_cast<int>(packet2.GetPacketType());


	bool boolValue2;
	short shortValue2;
	int integarValue2;
	float floatValue2;
	char charValue2;
	char string2[40];


	std::cout << "\n8. - 연산자를 이용한 패킷 분해" << '\n'
		<< "packet2 = packet2 - string2 - charValue2 - floatValue2 \n - integarValue2 - shortValue2 - boolValue2" << '\n';
	packet2 = packet2 - string2 - charValue2 - floatValue2 - integarValue2 - shortValue2 - boolValue2;

	std::cout << "\n9. 분해 후 값들" << '\n';
	std::cout << "boolValue2: " << boolValue2 << ", "
		<< "shortValue2: " << shortValue2 << ", "
		<< "integarValue2: " << integarValue2 << "\n"
		<< "floatValue2: " << floatValue2 << ", "
		<< "charValue2: " << charValue2 << ", "
		<< "string2: " << string2 << '\n';

	return 0;
}

