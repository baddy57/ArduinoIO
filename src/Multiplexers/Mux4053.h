#pragma once

#include "../Address.h"

using namespace ArduinoIO::Address;

namespace ArduinoIO
{
	namespace Multiplexers
	{
		class Mux4053
		{
			public: Mux4053(AddressBase* address, Pin pinA, Pin pinBC);

			public: void Prepare(byte port);//chiama address. prepare

			protected: AddressBase* _address;
			protected: Pin _pinA, _pinBC;
		};
	}
}