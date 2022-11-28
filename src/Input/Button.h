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
				wentTrueAt = millis();
				loginf("click detected on " << _address->GetPin());
#ifndef SIMULATION_MODE
				HandleValueChanged(true);
#endif
				oldRawValue = true;
			}
			else if (oldRawValue && millis() - wentTrueAt > DEBOUNCE_ms && !ReadFn(_address))
			{
				loginf("click RESET on " << _address->GetPin());
				oldRawValue = false;
			}
		}
	};
}