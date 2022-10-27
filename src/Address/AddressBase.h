#pragma once
#include <Arduino.h>

namespace ArduinoIO
{
	namespace Address
	{
		typedef byte Pin;

		class AddressBase
		{
			public:virtual void PrepareForReading() = 0;
		};
	}
}