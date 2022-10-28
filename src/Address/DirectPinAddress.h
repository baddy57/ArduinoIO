#pragma once

#include "AddressBase.h"

namespace ArduinoIO
{
	namespace Address
	{
		class DirectPinAddress : public AddressBase
		{
			public:DirectPinAddress(Pin pin);
			public:virtual void PrepareForReading();
			protected: Pin _pin;
		};
	}
}