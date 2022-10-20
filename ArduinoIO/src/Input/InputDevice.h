#pragma once

#include "Arduino.h"
#include "Address/Address.h"

using namespace IO::Address;

namespace IO
{
	class InputDeviceBase
	{
		public: virtual void read() = 0;
		public: BasicAddress* _address;
	};

	template <class T>
	class InputDevice : public InputDeviceBase
	{
		public: InputDevice(BasicAddress* address, void callback(T))
		{
			handleValueChanged = callback;
			_address = address;
		}

		protected: T oldValue;
		protected: T value;

		public: void (*handleValueChanged)(T);
	};
}