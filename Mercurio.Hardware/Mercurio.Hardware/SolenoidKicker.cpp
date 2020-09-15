#include "SolenoidKicker.h"

namespace Bas
{
	SolenoidKicker::SolenoidKicker(int pin, unsigned long kickDuration) : pin{ pin }, kickDuration{ kickDuration }
	{
	}

	SolenoidKicker::~SolenoidKicker()
	{
	}

	void SolenoidKicker::initialize()
	{
		pinMode(this->pin, OUTPUT);
		digitalWrite(this->pin, LOW);
	}

	void SolenoidKicker::update()
	{
		if (isKicking && 
			millis() - this->kickStartTime >= kickDuration)
		{
			isKicking = false;
			digitalWrite(this->pin, LOW);
		}
	}

	void SolenoidKicker::kick()
	{
		this->isKicking = true;
		this->kickStartTime = millis();
		digitalWrite(this->pin, HIGH);
	}
}