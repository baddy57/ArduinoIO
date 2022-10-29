#pragma once

#include "../Address.h"

namespace ArduinoIO
{
	class InputDeviceBase
	{
		public: virtual void read() = 0;
		public: AddressBase* _address;
	};

	template <class T>
	class InputDevice : public InputDeviceBase
	{
		public: InputDevice(AddressBase* address, void callback(T))
		{
			handleValueChanged = callback;
			_address = address;
		}

		protected: T oldValue;
		protected: T value;

		public: void (*handleValueChanged)(T);
	};
}