#pragma once

#include "../Address.h"

namespace ArduinoIO
{
	namespace Address
	{
		typedef byte Pin;
		class BasicAddress : AddressBase
		{
			public:BasicAddress(Pin pin);
			public:virtual void PrepareForReading();
			protected: Pin _pin;
		};
	}
}