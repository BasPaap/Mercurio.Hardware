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
	/// <summary>
	/// Reads commands that come in via the serial port.
	/// Commands should always be terminated with a \n character, which will not be considered part of the command.
	//  For instance, when "TURN_ON\n" is received, SerialCommandReader will return the command "TURN_ON".
	/// </summary>
	class SerialCommandReader
	{
		char readBuffer[maxCommandSize];
		char lastCommand[maxCommandSize];
		int numCharsInBuffer;
		void clearBuffer();
		
	public:
		SerialCommandReader();

		/// <summary>
		/// Updates the SerialCommandReaderButton. This method should be called once per loop.
		/// </summary>
		void update();

		/// <summary>
		/// Returns true if a command has been read and is still available.
		/// </summary>
		/// <returns>True if a command has been read and is still available.</returns>
		bool isCommandAvailable();

		/// <summary>
		/// Returns the last command received, if available.
		/// </summary>
		/// <param name="command">A pointer to a character array that will receive the command, if any.</param>
		/// <param name="size">The size of the character array.</param>
		void getLastCommand(char* command, int size);

		/// <summary>
		/// Clears the last read command, so that it will no longer be considered available until a new command is received.
		/// </summary>
		void clearLastCommand();
	};
}

#endif