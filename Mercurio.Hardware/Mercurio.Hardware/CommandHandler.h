#ifndef _COMMAND_HANDLER_h
#define _COMMAND_HANDLER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "SerialCommandReader.h"

namespace Bas
{
	class CommandHandler
	{
		using CallbackPointer = void(*)();
		Bas::SerialCommandReader serialCommandReader;

		static const int maxCallbacks = 10;
		int numCallbacks;
		char* commands[maxCallbacks];
		CallbackPointer callbacks[maxCallbacks];

	public:
		CommandHandler();

		void addCallback(char* command, CallbackPointer callback);
		void update();
	};
}

#endif