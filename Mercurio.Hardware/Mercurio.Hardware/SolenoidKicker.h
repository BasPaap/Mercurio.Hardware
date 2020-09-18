#ifndef _SOLENOIDKICKER_h
#define _SOLENOIDKICKER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

namespace Bas
{
	class SolenoidKicker
	{
		int pin;
		unsigned long kickDuration;
		unsigned long kickStartTime;
		bool isKicking;

	public:
		SolenoidKicker(int pin, unsigned long kickDuration);

		void initialize();
		void update();
		void kick();
	};
}

#endif