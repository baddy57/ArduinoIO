#pragma once

#include "AddressBase.h"
#include <ArduinoLightLogger.h>

namespace ArduinoIO
{
	class DirectPinAddress : public AddressBase
	{
		public: DirectPinAddress(pin pin);

		public: int16_t ReadInt() const;
		public: bool ReadBool() const;

		protected: pin _pin;
	};
}