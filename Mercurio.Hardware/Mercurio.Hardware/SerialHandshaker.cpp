#include "SerialHandshaker.h"


Bas::SerialHandshaker::SerialHandshaker(char readyMessage[BUFFER_SIZE], char expectedResponse[BUFFER_SIZE], char confirmationMessage[BUFFER_SIZE]) : isResponseReceived{ false }, numCharsInBuffer{ 0 }
{
	strcpy(this->readyMessage, readyMessage);
	strcpy(this->expectedResponse, expectedResponse);
	strcpy(this->confirmationMessage, confirmationMessage);
	clearBuffer();
}

Bas::SerialHandshaker::~SerialHandshaker()
{
}

void Bas::SerialHandshaker::update()
{	
	if (Serial.available())
	{
		if (numCharsInBuffer >= BUFFER_SIZE)
		{
			clearBuffer();
		}
				
		readBuffer[numCharsInBuffer] = Serial.read();
		numCharsInBuffer++;
		
		if (readBuffer[numCharsInBuffer - 1] == '\n')
		{
			readBuffer[numCharsInBuffer -1] = '\0';
			
			if (strcmp(expectedResponse, readBuffer) == 0)
			{
				Serial.println(confirmationMessage);
				this->isResponseReceived = true;
			}
			else
			{				
				clearBuffer();
			}
		}
	}	
	else
	{
		Serial.println(readyMessage);
	}
}

void Bas::SerialHandshaker::clearBuffer()
{
	numCharsInBuffer = 0;
	for (size_t i = 0; i < BUFFER_SIZE; i++)
	{
		readBuffer[i] = '\0';
	}
}

bool Bas::SerialHandshaker::isConnected()
{
	return this->isResponseReceived;
}
