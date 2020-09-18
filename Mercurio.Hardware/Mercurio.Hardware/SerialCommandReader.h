#ifndef _SERIAL_COMMAND_READER_h
#define _SERIAL_COMMAND_READER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#define MAX_COMMAND_SIZE 10

namespace Bas
{
	class SerialCommandReader
	{
		char readBuffer[MAX_COMMAND_SIZE];
		char lastCommand[MAX_COMMAND_SIZE];
		int numCharsInBuffer;
		void clearBuffer();
		
	public:
		SerialCommandReader();
		~SerialCommandReader();		

		void update();
		bool isCommandAvailable();
		void getLastCommand(char* command, int size);
		void clearLastCommand();
	};
}

#endif