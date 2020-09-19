#include "CommandHandler.h"

Bas::CommandHandler::CommandHandler() : numCallbacks{ 0 }
{
}

void Bas::CommandHandler::addCallback(const char* command, CallbackPointer callback)
{
	if (this->numCallbacks < maxCallbacks)
	{
		this->commands[numCallbacks] = command;
		this->callbacks[numCallbacks] = callback;
		this->numCallbacks++;
	}
}

void Bas::CommandHandler::update()
{
	this->serialCommandReader.update();
	if (this->serialCommandReader.isCommandAvailable())
	{
		char command[maxCommandSize];
		this->serialCommandReader.getLastCommand(command, maxCommandSize);

		for (size_t i = 0; i < this->numCallbacks; i++)
		{
			if (strcmp(this->commands[i], command) == 0)
			{
				this->callbacks[i]();
				this->serialCommandReader.clearLastCommand();
			}
		}
	}
}
