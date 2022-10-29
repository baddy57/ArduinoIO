#pragma once

#include "../Address.h"

namespace ArduinoIO
{
	class InputDeviceBase
	{
		public: virtual void Evaluate() = 0;
		public: AddressBase* _address;
		protected: int oldRawValue;
	};

	template <class T>
	class InputDevice : public InputDeviceBase
	{
		public: InputDevice(AddressBase* address, void callback(T))
		{
			handleValueChanged = callback;
			_address = address;
		}

		public: void Evaluate();

		protected: T GetLogicalValue(int rawValue);
		protected: void (*handleValueChanged)(T);
	};
}