#pragma once

#include "../Address.h"

namespace ArduinoIO
{
	class InputDeviceBase
	{
		public: virtual void Evaluate() = 0;
		public: AddressBase* _address;
		protected: int (*ReadFn)(AddressBase*);

		protected: int oldRawValue;
		protected: virtual bool ValueChanged(int, int);
	};

	template <typename T>
	class InputDevice : public InputDeviceBase
	{
		public: InputDevice(AddressBase* address, void handleValueChanged(T), int readFn(AddressBase*))
		{
			HandleValueChanged = handleValueChanged;
			ReadFn = readFn;
			_address = address;
		}

		public: void Evaluate();

		protected: virtual T GetLogicalValue(int rawValue) { return rawValue; }
		protected: void (*HandleValueChanged)(T);
	};
}