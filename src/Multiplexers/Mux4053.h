#pragma once

#include "../Address/AddressBase.h"
#include "MultiplexerBase.h"

namespace ArduinoIO
{
	class Mux4053 : public MultiplexerBase
	{
		public: Mux4053(AddressBase* address, Pin pinA, Pin pinBC);

		public: void Prepare(byte port) const override;//base.prepare e setta i selettori

		protected: Pin _pinA, _pinBC;
	};
}