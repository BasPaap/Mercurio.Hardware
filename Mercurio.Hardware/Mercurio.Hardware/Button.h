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
		using InputEvent = void(*)();
		int pin;
		int lastDebouncedButtonState = HIGH;
		unsigned long lastDebounceTime;
		unsigned long debounceDelay;
		InputEvent risingEvent;
		InputEvent fallingEvent;
		int debouncedState;

	public:
		Button(int pin, unsigned long debounceDelay);
		~Button();

		void initialize(InputEvent risingEvent, InputEvent fallingEvent);
		void update();
		int getState();
	};
}

#endif

