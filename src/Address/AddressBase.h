#pragma once
#include <Arduino.h>

typedef byte Pin;

namespace ArduinoIO
{
	namespace Address
	{
		class AddressBase
		{
			public:virtual void PrepareForReading() = 0;
		};
	}
}