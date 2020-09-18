#include "SerialHandshaker.h"

Bas::SerialHandshaker::SerialHandshaker(char readyMessage[BUFFER_SIZE], char expectedResponse[BUFFER_SIZE], char confirmationMessage[BUFFER_SIZE]) : isResponseReceived{ false }
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
		char command[BUFFER_SIZE];
		this->serialCommandReader.getLastCommand(command, BUFFER_SIZE);
				
		if (strcmp(expectedResponse, command) == 0)
		{
			Serial.println(confirmationMessage);
			this->isResponseReceived = true;
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
