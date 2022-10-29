#pragma once
#include <Arduino.h>

namespace ArduinoIO
{
	class MultiplexerBase
	{
		protected: MultiplexerBase(AddressBase* address) : _address(address) {}

		public: virtual void Prepare(byte port) { _address->PrepareForReading(); }
		public: int ReadInt() { return _address->ReadInt(); }
		public: bool ReadBool() { return _address->ReadBool(); }

		public: AddressBase* _address;
	};
}