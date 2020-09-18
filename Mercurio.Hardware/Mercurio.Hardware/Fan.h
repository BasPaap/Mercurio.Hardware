
#ifndef _FAN_h
#define _FAN_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

namespace Bas
{
	class Fan
	{
		int pin;

	public:
		Fan(int pin);

		void initialize();
		void turnOn();
		void turnOff();
	};
}
#endif