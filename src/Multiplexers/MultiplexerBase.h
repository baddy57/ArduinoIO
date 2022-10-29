#pragma once
#include <Arduino.h>

namespace ArduinoIO
{
	class MultiplexerBase
	{
		protected: MultiplexerBase(AddressBase* address) : _address(address) {}
		public: virtual void Prepare(byte port) { _address->PrepareForReading(); }
		public: AddressBase* _address;
	};
}