#include "CommandHandler.h"

Bas::CommandHandler::CommandHandler() : numCallbacks{ 0 }
{
}

void Bas::CommandHandler::addCallback(char* command, CallbackPointer callback)
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
		char command[MAX_COMMAND_SIZE];
		this->serialCommandReader.getLastCommand(command, MAX_COMMAND_SIZE);

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
