#pragma once

#include "../Address/AddressBase.h"

namespace ArduinoIO
{
	namespace Multiplexer
	{
		class Mux4053
		{
			public: Mux4053(BasicAddress* address, Pin pinA, Pin pinBC);

			public: void Prepare(byte port);//chiama address. prepare

			protected: BasicAddress* _address;
			protected: Pin _pinA, _pinBC;
		};
	}
}