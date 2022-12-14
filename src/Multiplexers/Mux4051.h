#pragma once

#include "../Address/AddressBase.h"
#include "MultiplexerBase.h"

namespace ArduinoIO
{
	class Mux4051 : public MultiplexerBase
	{
		public: Mux4051(AddressBase* address, pin pinA, pin pinB, pin pinC);

		public: void Prepare(byte port) const override;//base.prepare e setta i selettori

		protected: pin _pinA, _pinB, _pinC;
	};
}