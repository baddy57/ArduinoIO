#pragma once

#include "InputDevice.h"
#include <Arduino.h>

#define DEBOUNCE_ms 20

namespace ArduinoIO
{
	inline int16_t ReadTap(AddressBase* a)
	{
		return a->ReadBool();
	}

	class Button : public DigitalInput
	{
		public: Button(AddressBase* address, void callback(bool))
			: DigitalInput(address, callback)
		{
			oldRawValue = false;
		}

		private: unsigned long wentTrueAt;

		public: void Evaluate() override
		{
			if (!oldRawValue && ReadFn(_address))
			{
				HandleValueChanged(true);
				oldRawValue = true;
				wentTrueAt = millis();
			}
			else if (oldRawValue && millis() - wentTrueAt > DEBOUNCE_ms)
			{
				oldRawValue = false;
			}
		}
	};
}