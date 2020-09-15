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
		pinMode(this->pin, OUTPUT);
		digitalWrite(this->pin, LOW);
	}

	void Fan::turnOn()
	{
		digitalWrite(this->pin, HIGH);
	}

	void Fan::turnOff()
	{
		digitalWrite(this->pin, LOW);
	}
}
