/*
 Name:		Mercurio.ino
 Created:	9/15/2020 9:56:07 PM
 Author:	Bas Paap
*/

#include "Button.h"
#include "Fan.h"
#include "SolenoidKicker.h"
#include "SerialHandshaker.h"
#include "CommandHandler.h"

const int firstFanButtonPin = 2;
const int secondFanButtonPin = 3;
const int solenoidButtonPin = 4;
const int firstFanPin = 5;
const int secondFanPin = 6;
const int solenoidKickerPin = 7;
const unsigned long kickDuration = 200;
const unsigned long debounceDelay = 50;

Bas::Button firstFanButton{ firstFanButtonPin, debounceDelay };
Bas::Button secondFanButton{ secondFanButtonPin, debounceDelay };
Bas::Button solenoidButton{ solenoidButtonPin, debounceDelay };

Bas::Fan firstFan{ firstFanPin };
Bas::Fan secondFan{ secondFanPin };

Bas::SolenoidKicker solenoidKicker{ solenoidKickerPin, kickDuration };

Bas::SerialHandshaker serialHandshaker{ "Beep", "Boop", "OK" };
Bas::CommandHandler commandHandler;

// the setup function runs once when you press reset or power the board
void setup() 
{
	Serial.begin(9600);
	while (!Serial) {
		; // wait for serial port to connect. Needed for native USB port only
	}

	Serial.println("Mercurio hardware controller v1.0");

	firstFanButton.initialize(turnFirstFanOn, turnFirstFanOff);
	secondFanButton.initialize(turnSecondFanOn, turnSecondFanOff);
	solenoidButton.initialize(activateSolenoidKicker);

	firstFan.initialize();
	secondFan.initialize();
	solenoidKicker.initialize();

	commandHandler.addCallback("FAN1_ON", turnFirstFanOn);
	commandHandler.addCallback("FAN1_OFF", turnFirstFanOff);
	commandHandler.addCallback("FAN2_ON", turnSecondFanOn);
	commandHandler.addCallback("FAN2_OFF", turnSecondFanOff);
	commandHandler.addCallback("KICK", activateSolenoidKicker);	
}

// the loop function runs over and over again until power down or reset
void loop() 
{
	if (serialHandshaker.isConnected())
	{
		commandHandler.update();
	}
	else
	{
		serialHandshaker.update();
	}

	firstFanButton.update();
	secondFanButton.update();
	solenoidButton.update();  

	solenoidKicker.update();
}

void activateSolenoidKicker()
{
	solenoidKicker.kick();
}

void turnFirstFanOn() 
{
	firstFan.turnOn();
}

void turnSecondFanOn()
{
	secondFan.turnOn();
}

void turnFirstFanOff()
{
	firstFan.turnOff();
}

void turnSecondFanOff()
{
	secondFan.turnOff();
}