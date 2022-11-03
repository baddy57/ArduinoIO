#pragma once
#include <Arduino.h>

namespace ArduinoIO
{
	typedef byte Pin;

	class AddressBase
	{
		public: virtual void PrepareForReading() const {}
		public: virtual int ReadInt() const { return 0; }
		public: virtual bool ReadBool() const { return false; }
	};
}