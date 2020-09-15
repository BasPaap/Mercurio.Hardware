#include "Fan.h"

namespace Bas
{
	Fan::Fan(int pin) : pin{ pin }
	{
	}

	Fan::~Fan()
	{
	}

	void Fan::initialize()
	{
		Serial.print("Initializing fan on pin ");
		Serial.println(this->pin);

		pinMode(this->pin, OUTPUT);
		digitalWrite(this->pin, LOW);
	}

	void Fan::turnOn()
	{
		Serial.print("Turning on fan on pin ");
		Serial.println(this->pin);

		digitalWrite(this->pin, HIGH);
	}

	void Fan::turnOff()
	{
		Serial.print("Turning off fan on pin ");
		Serial.println(this->pin);

		digitalWrite(this->pin, LOW);
	}
}
