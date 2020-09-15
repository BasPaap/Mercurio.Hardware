// 
// 
// 

#include "Button.h"
namespace Bas
{
	Button::Button(int pin, unsigned long debounceDelay) : pin{ pin }, debounceDelay{ debounceDelay }, risingCallback{ NULL }, fallingCallback{ NULL }
	{
	}

	Button::~Button()
	{
	}

	void Button::initialize(CallbackPointer risingEvent)
	{
		this->initialize(risingEvent, NULL);
	}

	void Button::initialize(CallbackPointer risingEvent, CallbackPointer fallingEvent)
	{
		this->risingCallback = risingEvent;
		this->fallingCallback = fallingEvent;
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
					Serial.println("Button debounced on HIGH.");
					this->risingCallback();
				}

				if (this->fallingCallback == NULL && currentButtonState == LOW)
				{
					Serial.println("Button debounced on LOW.");
					this->fallingCallback();
				}
			}
		}
	}

	int Button::getState()
	{
		return this->debouncedState;
	}
}
