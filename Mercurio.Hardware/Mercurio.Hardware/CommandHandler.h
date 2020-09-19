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
	/// <summary>
	/// Class that handles commands that are sent to the arduino via the Serial port.
	/// </summary>
	class CommandHandler
	{
		using CallbackPointer = void(*)();
		Bas::SerialCommandReader serialCommandReader;

		static const int maxCallbacks = 10;
		int numCallbacks;
		const char* commands[maxCallbacks];
		CallbackPointer callbacks[maxCallbacks];

	public:
		CommandHandler();

		/// <summary>
		/// Adds a callback to be called when a certain command is called.
		/// </summary>
		/// <param name="command">The command to respond to.</param>
		/// <param name="callback">The callback to call.</param>
		void addCallback(const char* command, CallbackPointer callback);

		/// <summary>
		/// Updates the CommandHandler state. This method should be called once per loop.
		/// </summary>
		void update();
	};
}

#endif