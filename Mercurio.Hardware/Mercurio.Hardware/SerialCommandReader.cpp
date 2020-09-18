#include "SerialCommandReader.h"

Bas::SerialCommandReader::SerialCommandReader() : numCharsInBuffer{ 0 }
{
	clearBuffer();
	clearLastCommand();
}

Bas::SerialCommandReader::~SerialCommandReader()
{
}

void Bas::SerialCommandReader::update()
{
	if (Serial.available())
	{
		if (numCharsInBuffer >= MAX_COMMAND_SIZE)
		{
			clearBuffer();
		}

		readBuffer[numCharsInBuffer] = Serial.read();
		numCharsInBuffer++;

		if (readBuffer[numCharsInBuffer - 1] == '\n')
		{
			readBuffer[numCharsInBuffer -1] = '\0';

			// complete command found.
			clearLastCommand();
			strcpy(lastCommand, readBuffer);
			clearBuffer();			
		}
	}
}

bool Bas::SerialCommandReader::isCommandAvailable()
{
	return strlen(lastCommand) > 0;
}

void Bas::SerialCommandReader::getLastCommand(char* command, int size)
{
	strncpy(command, lastCommand, size);
	//clearLastCommand();
}

void Bas::SerialCommandReader::clearBuffer()
{
	numCharsInBuffer = 0;
	for (size_t i = 0; i < MAX_COMMAND_SIZE; i++)
	{
		readBuffer[i] = '\0';
	}
}

void Bas::SerialCommandReader::clearLastCommand()
{
	lastCommand[0] = '\0';
}