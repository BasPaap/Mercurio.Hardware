/*
 Name:		Mercurio.ino
 Created:	9/15/2020 9:56:07 PM
 Author:	Bas Paap
*/

#include "Button.h"
#include "Fan.h"
#include "SolenoidKicker.h"

const int firstFanButtonPin = 2;
const int secondFanButtonPin = 3;
const int solenoidButtonPin = 4;
const int firstFanPin = 5;
const int secondFanPin = 6;
const int solenoidKickerPin = 7;
const unsigned long kickDuration = 500;
const unsigned long debounceDelay = 50;

Bas::Button firstFanButton{ firstFanButtonPin, debounceDelay };
Bas::Button secondFanButton{ secondFanButtonPin, debounceDelay };
Bas::Button solenoidButton{ solenoidButtonPin, debounceDelay };

Bas::Fan firstFan{ firstFanPin };
Bas::Fan secondFan{ secondFanPin };

Bas::SolenoidKicker solenoidKicker{ solenoidKickerPin, kickDuration };

// the setup function runs once when you press reset or power the board
void setup() 
{
	Serial.begin(9600);

	firstFanButton.initialize(turnFirstFanOn, turnFirstFanOff);
	secondFanButton.initialize(turnSecondFanOn, turnSecondFanOff);
	solenoidButton.initialize(activateSolenoidKicker, doNothing);

	firstFan.initialize();
	secondFan.initialize();
	solenoidKicker.initialize();
}

// the loop function runs over and over again until power down or reset
void loop() 
{
	firstFanButton.update();
	secondFanButton.update();
	solenoidButton.update();  

	solenoidKicker.update();
}

void activateSolenoidKicker()
{
	solenoidKicker.kick();
}

void doNothing()
{

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