#ifndef _SERIAL_COMMAND_READER_h
#define _SERIAL_COMMAND_READER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

constexpr auto maxCommandSize = 10;

namespace Bas
{
	class SerialCommandReader
	{
		char readBuffer[maxCommandSize];
		char lastCommand[maxCommandSize];
		int numCharsInBuffer;
		void clearBuffer();
		
	public:
		SerialCommandReader();

		void update();
		bool isCommandAvailable();
		void getLastCommand(char* command, int size);
		void clearLastCommand();
	};
}

#endif