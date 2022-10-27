#pragma once

#include "../Address/AddressBase.h"

using namespace ArduinoIO::Address;

namespace ArduinoIO
{
	namespace Multiplexer
	{
		class Mux4051
		{
			public: Mux4051(AddressBase* address, Pin pinA, Pin pinB, Pin pinC);

			public: void Prepare(byte port);//chiama address. prepare

			protected: AddressBase* _address;
			protected: Pin _pinA, _pinB, _pinC;
		};
	}
}