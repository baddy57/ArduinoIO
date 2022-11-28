#pragma once
#include <Arduino.h>
#include <ArduinoLightLogger.h>

namespace ArduinoIO
{
	typedef byte pin;

	class AddressBase
	{
		public: virtual void PrepareForReading() const {};
		public: virtual int16_t ReadInt() const = 0;
		public: virtual bool ReadBool() const = 0;
		public: virtual pin GetPin() const = 0;
	};
}