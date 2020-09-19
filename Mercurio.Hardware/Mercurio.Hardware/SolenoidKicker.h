#ifndef _SOLENOIDKICKER_h
#define _SOLENOIDKICKER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

namespace Bas
{
	/// <summary>
	/// Encapsulates a solenoid-based kicker that can activate a solenoid for a specified amount of time.
	/// </summary>
	class SolenoidKicker
	{
		int pin;
		unsigned long kickDuration;
		unsigned long kickStartTime;
		bool isKicking;

	public:
		/// <summary>
		/// Constructs a SolenoidKicker object.
		/// </summary>
		/// <param name="pin">The pin the solenoid is connected to.</param>
		/// <param name="kickDuration">Duration in milliseconds during which the solenoid should be active.</param>
		/// <returns></returns>
		SolenoidKicker(int pin, unsigned long kickDuration);

		/// <summary>
		/// Initializes the SolenoidKicker object. Should be called in the setup() method.
		/// </summary>
		void initialize();

		/// <summary>
		/// Updates the SolenoidKicker state. This method should be called once per loop.
		/// </summary>
		void update();

		/// <summary>
		/// Activates the solenoid for a specified amount of time.
		/// </summary>
		void kick();
	};
}

#endif