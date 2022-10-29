#pragma once

#include "AddressBase.h"

namespace ArduinoIO
{
	class DirectPinAddress : public AddressBase
	{
		public: DirectPinAddress(Pin pin);

		protected: void PrepareForReading();
		protected: int ReadInt();
		protected: bool ReadBool();

		protected: Pin _pin;
	};
}