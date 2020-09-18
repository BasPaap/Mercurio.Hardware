#ifndef _SERIAL_COMMAND_READER_h
#define _SERIAL_COMMAND_READER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#define BUFFER_SIZE 10

namespace Bas
{
	class SerialCommandReader
	{
		char readBuffer[BUFFER_SIZE];
		char lastCommand[BUFFER_SIZE];
		int numCharsInBuffer;
		void clearBuffer();
		void clearLastCommand();

	public:
		SerialCommandReader();
		~SerialCommandReader();		

		void update();
		bool isCommandAvailable();
		void getLastCommand(char* command, int size);
	};
}

#endif