#pragma once

#include "AddressBase.h"

namespace ArduinoIO
{
	class DirectPinAddress : public AddressBase
	{
		public: DirectPinAddress(Pin pin);

		public: void PrepareForReading() const;
		public: int16_t ReadInt() const;
		public: bool ReadBool() const;

		protected: Pin _pin;
	};
}