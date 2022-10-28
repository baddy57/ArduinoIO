#pragma once
#include <Arduino.h>

namespace ArduinoIO
{
	typedef int Pin;
	namespace Address
	{
		class AddressBase
		{
			public:virtual void PrepareForReading() = 0;
		};
	}
}