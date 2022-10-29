#pragma once

#include "../Address.h"

namespace ArduinoIO
{
	class InputDeviceBase
	{
		public: virtual void Evaluate() = 0;
		public: AddressBase* _address;
		protected: int oldRawValue;
		protected: int(*ReadFn)(AddressBase*);
	};

	template <class T>
	class InputDevice : public InputDeviceBase
	{
		public: InputDevice(AddressBase* address, void handleValueChanged(T), int readFn(AddressBase*))
		{
			HandleValueChanged = handleValueChanged;
			ReadFn = readFn;
			_address = address;
		}

		public: void Evaluate();

		protected: T GetLogicalValue(int rawValue);
		protected: void (*HandleValueChanged)(T);
	};
}