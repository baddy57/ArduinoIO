#pragma once
#include <Arduino.h>

namespace ArduinoIO
{
	typedef int Pin;

	class AddressBase
	{
		public:virtual void PrepareForReading() = 0;
	};
}