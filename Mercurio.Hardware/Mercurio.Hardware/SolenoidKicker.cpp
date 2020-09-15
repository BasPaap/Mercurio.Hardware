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
		Serial.print("Initializing solenoid kicker on pin ");
		Serial.println(this->pin);

		pinMode(this->pin, OUTPUT);
		digitalWrite(this->pin, LOW);
	}

	void SolenoidKicker::update()
	{
		if (isKicking && 
			millis() - this->kickStartTime >= kickDuration)
		{
			Serial.println("Turning solenoid kicker off.");
			
			isKicking = false;
			digitalWrite(this->pin, LOW);
		}
	}

	void SolenoidKicker::kick()
	{
		Serial.println("Starting solenoid kick.");
		
		this->isKicking = true;
		this->kickStartTime = millis();
		digitalWrite(this->pin, HIGH);
	}
}