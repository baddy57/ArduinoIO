#pragma once

#include "../Address.h"
#include <ArduinoLightLogger.h>

namespace ArduinoIO
{
	class InputDeviceBase
	{
		public: virtual void Evaluate() = 0;
		public: AddressBase* _address;
		protected: int16_t(*ReadFn)(AddressBase*);

		protected: int16_t oldRawValue = 0;
		protected: virtual bool ValueChanged(int16_t, int16_t);
	};

	template <typename T>
	class InputDevice : public InputDeviceBase
	{
		public: InputDevice(AddressBase* address, void handleValueChanged(T), int16_t readFn(AddressBase*))
		{
			HandleValueChanged = handleValueChanged;
			ReadFn = readFn;
			_address = address;
		}

		//https://stackoverflow.com/questions/10632251/undefined-reference-to-template-function
		public: virtual void Evaluate()
		{
			int rawValue = ReadFn(_address);
			if (ValueChanged(oldRawValue, rawValue))
			{
				loginf("raw value changed from " << oldRawValue << " to " << rawValue);
				T value = GetLogicalValue(rawValue);
				loginf("logical value is " << value);
#ifndef SIMULATION_MODE
				HandleValueChanged(value);
#endif
				oldRawValue = value;
			}
		}

		protected: virtual T GetLogicalValue(int16_t rawValue) { return rawValue; }
		protected: void (*HandleValueChanged)(T);
	};
}