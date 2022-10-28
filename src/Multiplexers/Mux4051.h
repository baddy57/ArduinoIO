#pragma once

#include "../Address/AddressBase.h"
#include "MultiplexerBase.h"

namespace ArduinoIO
{
	namespace Multiplexers
	{
		class Mux4051 : public MultiplexerBase
		{
			public: Mux4051(Address::AddressBase* address, Pin pinA, Pin pinB, Pin pinC);

			public: void Prepare(byte port);//chiama address. prepare

			protected: Address::AddressBase* _address;
			protected: Pin _pinA, _pinB, _pinC;
		};
	}
}