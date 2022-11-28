#pragma once

#include "../Address/AddressBase.h"
#include "MultiplexerBase.h"

namespace ArduinoIO
{
	class Mux4053 : public MultiplexerBase
	{
		public: Mux4053(AddressBase* address, pin pinA, pin pinBC);

		public: void Prepare(byte port) const override;//base.prepare e setta i selettori

		protected: pin _pinA, _pinBC;
	};
}