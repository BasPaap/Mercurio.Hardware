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
		char readyMessage[MAX_COMMAND_SIZE];
		char expectedResponse[MAX_COMMAND_SIZE];
		char confirmationMessage[MAX_COMMAND_SIZE];
		bool isResponseReceived;

		Bas::SerialCommandReader serialCommandReader;

	public:
		SerialHandshaker(char readyMessage[MAX_COMMAND_SIZE], char expectedResponse[MAX_COMMAND_SIZE], char confirmationMessage[MAX_COMMAND_SIZE]);

		void update();
		bool isConnected();
	};
}

#endif