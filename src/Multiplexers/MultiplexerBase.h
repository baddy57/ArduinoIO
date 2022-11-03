#pragma once
#include <Arduino.h>

namespace ArduinoIO
{
	class MultiplexerBase
	{
		protected: MultiplexerBase(AddressBase* address) : _address(address) {}

		public: virtual void Prepare(byte port) const
		{
			//Log::debug("preparing mux port " + port);
			_address->PrepareForReading();
		}
		public: int ReadInt() const { return _address->ReadInt(); }
		public: bool ReadBool() const { return _address->ReadBool(); }

		public: AddressBase* _address;
	};
}