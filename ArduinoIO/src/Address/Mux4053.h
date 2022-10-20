#pragma once

#include "BasicAddress.h"

namespace ArduinoIO
{
	namespace Address
	{
		class Mux4053
		{
			public: Mux4053(BasicAddress* address, int pinA, int pinBC);
			public: void Prepare(byte port);//chiama address. prepare
			protected: BasicAddress* _address;
		};
	}
}