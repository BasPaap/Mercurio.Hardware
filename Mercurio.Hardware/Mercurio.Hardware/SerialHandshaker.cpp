#include "SerialHandshaker.h"

Bas::SerialHandshaker::SerialHandshaker(char readyMessage[MAX_COMMAND_SIZE], char expectedResponse[MAX_COMMAND_SIZE], char confirmationMessage[MAX_COMMAND_SIZE]) : isResponseReceived{ false }
{
	strcpy(this->readyMessage, readyMessage);
	strcpy(this->expectedResponse, expectedResponse);
	strcpy(this->confirmationMessage, confirmationMessage);
}

Bas::SerialHandshaker::~SerialHandshaker()
{
}

void Bas::SerialHandshaker::update()
{	
	this->serialCommandReader.update();
	if (this->serialCommandReader.isCommandAvailable())
	{
		char command[MAX_COMMAND_SIZE];
		this->serialCommandReader.getLastCommand(command, MAX_COMMAND_SIZE);
				
		if (strcmp(expectedResponse, command) == 0)
		{
			Serial.println(confirmationMessage);
			this->isResponseReceived = true;
			this->serialCommandReader.clearLastCommand();
		}		
	}
	else
	{
		Serial.println(this->readyMessage);
	}
}

bool Bas::SerialHandshaker::isConnected()
{
	return this->isResponseReceived;
}
