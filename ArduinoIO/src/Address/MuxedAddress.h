#pragma once

#include "BasicAddress.h"
#include "Mux4053.h"
#include "Mux4051.h"

namespace ArduinoIO
{
	namespace Address
	{
		class MuxedAddress : public BasicAddress, Mux4051
		{
			public:MuxedAddress(Mux4051* mux, bool a, bool b, bool c);
			public:MuxedAddress(Mux4051* mux, byte muxPort);
			public:virtual void PrepareForReading();//chiama base. prepare
		};
	}
}