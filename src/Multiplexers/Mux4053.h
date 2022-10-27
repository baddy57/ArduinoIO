#pragma once

#include "../Address/AddressBase.h"

namespace ArduinoIO
{
	namespace Multiplexer
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