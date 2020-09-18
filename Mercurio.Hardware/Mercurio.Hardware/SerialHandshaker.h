#ifndef _SERIAL_HANDSHAKER_h
#define _SERIAL_HANDSHAKER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "SerialCommandReader.h"

namespace Bas
{
	class SerialHandshaker
	{		
		char readyMessage[BUFFER_SIZE];
		char expectedResponse[BUFFER_SIZE];
		char confirmationMessage[BUFFER_SIZE];
		bool isResponseReceived;

		Bas::SerialCommandReader serialCommandReader;

	public:
		SerialHandshaker(char readyMessage[BUFFER_SIZE], char expectedResponse[BUFFER_SIZE], char confirmationMessage[BUFFER_SIZE]);
		~SerialHandshaker();

		void update();
		bool isConnected();
	};
}

#endif