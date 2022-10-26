#pragma once

#include "../Address/AddressBase.h"

namespace ArduinoIO
{
	namespace Multiplexer
	{
		class Mux4051
		{
			public: Mux4051(BasicAddress* address, Pin pinA, Pin pinB, Pin pinC);

			public: void Prepare(byte port);//chiama address. prepare

			protected: BasicAddress* _address;
			protected: Pin _pinA, _pinB, _pinC;
		};
	}
}