// Button.h

#ifndef _BUTTON_h
#define _BUTTON_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
namespace Bas
{
	class Button
	{
		using CallbackPointer = void(*)();
		int pin;
		int lastDebouncedButtonState = HIGH;
		unsigned long lastDebounceTime;
		unsigned long debounceDelay;
		CallbackPointer risingCallback;
		CallbackPointer fallingCallback;
		int debouncedState;

	public:
		Button(int pin, unsigned long debounceDelay);
		~Button();

		void initialize(CallbackPointer fallingCallback);
		void initialize(CallbackPointer fallingCallback, CallbackPointer risingCallback);
		void update();
		int getState();
	};
}

#endif

