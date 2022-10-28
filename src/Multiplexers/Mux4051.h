#pragma once

#include "../Address.h"

using namespace ArduinoIO::Address;

namespace ArduinoIO
{
	namespace Multiplexers
	{
		class Mux4051 : public MultiplexerBase
		{
			public: Mux4051(AddressBase* address, Pin pinA, Pin pinB, Pin pinC);

			public: void Prepare(byte port);//chiama address. prepare

			protected: AddressBase* _address;
			protected: Pin _pinA, _pinB, _pinC;
		};
	}
}