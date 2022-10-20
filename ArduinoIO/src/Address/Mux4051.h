#pragma once

#include "BasicAddress.h"

namespace IO
{
	namespace Address
	{
		class Mux4051
		{
			public: Mux4051(BasicAddress* address, int pinA, int pinB, int pinC);
			public: void Prepare(byte port);//chiama address. prepare
			protected: BasicAddress* _address;
		};
	}
}