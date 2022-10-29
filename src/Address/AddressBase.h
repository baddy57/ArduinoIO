#pragma once
#include <Arduino.h>

namespace ArduinoIO
{
	typedef int Pin;

	class AddressBase
	{
		public: virtual void PrepareForReading() = 0;
		public: virtual int ReadInt() = 0;
		public: virtual bool ReadBool() = 0;
	};
}