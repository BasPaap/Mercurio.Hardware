
#ifndef _FAN_h
#define _FAN_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

namespace Bas
{
	/// <summary>
	/// Encapsulates a fan connected to the arduino.
	/// </summary>
	class Fan
	{
		int pin;

	public:
		/// <summary>
		/// Constructs the Fan object.
		/// </summary>
		/// <param name="pin">The pin the fan is connected to.</param>
		/// <returns></returns>
		Fan(int pin);

		/// <summary>
		/// Initializes the Fan object. Should be called in the setup() method.
		/// </summary>
		void initialize();

		/// <summary>
		/// Turns the fan on by pulling the pin HIGH.
		/// </summary>
		void turnOn();
		
		/// <summary>
		/// Turns the fan off by pulling the pin LOW.
		/// </summary>
		void turnOff();
	};
}
#endif