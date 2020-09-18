#ifndef _SERIAL_HANDSHAKER_h
#define _SERIAL_HANDSHAKER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

namespace Bas
{
	class SerialHandshaker
	{
#define BUFFER_SIZE 10
		char readBuffer[BUFFER_SIZE];
		int numCharsInBuffer;
		
		char readyMessage[BUFFER_SIZE];
		char expectedResponse[BUFFER_SIZE];
		char confirmationMessage[BUFFER_SIZE];
		bool isResponseReceived;

	public:
		SerialHandshaker(char readyMessage[BUFFER_SIZE], char expectedResponse[BUFFER_SIZE], char confirmationMessage[BUFFER_SIZE]);
		~SerialHandshaker();

		void update();
		void clearBuffer();
		bool isConnected();
	};
}

#endif