// 
// 
// 

#include "Button.h"
namespace Bas
{
	Button::Button(int pin, unsigned long debounceDelay) : pin{ pin }, debounceDelay{ debounceDelay }
	{
	}

	Button::~Button()
	{
	}

	void Button::initialize(InputEvent risingEvent, InputEvent fallingEvent)
	{
		this->risingEvent = risingEvent;
		this->fallingEvent = fallingEvent;
		pinMode(this->pin, INPUT_PULLUP);
	}

	void Button::update()
	{
		int currentButtonState = digitalRead(this->pin);
		unsigned long now = millis();

		if (currentButtonState != this->lastDebouncedButtonState)
		{
			if (now - this->lastDebounceTime > this->debounceDelay)
			{
				// A debounced button change has occurred!
				this->lastDebounceTime = now;
				this->lastDebouncedButtonState = currentButtonState;
				this->debouncedState = currentButtonState;

				// Call the appropriate callback function
				if (currentButtonState == HIGH)
				{
					this->risingEvent();
				}

				if (currentButtonState == LOW)					
				{
					this->fallingEvent();
				}
			}
		}
	}

	int Button::getState()
	{
		return this->debouncedState;
	}
}
