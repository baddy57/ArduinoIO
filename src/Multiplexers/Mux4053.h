#pragma once

#include "../Address/AddressBase.h"
#include "MultiplexerBase.h"

namespace ArduinoIO
{
	namespace Multiplexers
	{
		class Mux4053 : public MultiplexerBase
		{
			public: Mux4053(Address::AddressBase* address, Pin pinA, Pin pinBC);

			public: void Prepare(byte port);//chiama address. prepare

			protected: Address::AddressBase* _address;
			protected: Pin _pinA, _pinBC;
		};
	}
}