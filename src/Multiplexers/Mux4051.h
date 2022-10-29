#pragma once

#include "../Address/AddressBase.h"
#include "MultiplexerBase.h"

namespace ArduinoIO
{
	class Mux4051 : public MultiplexerBase
	{
		public: Mux4051(AddressBase* address, Pin pinA, Pin pinB, Pin pinC);

		public: void Prepare(byte port);//chiama address. prepare

		protected: AddressBase* _address;
		protected: Pin _pinA, _pinB, _pinC;
	};
}