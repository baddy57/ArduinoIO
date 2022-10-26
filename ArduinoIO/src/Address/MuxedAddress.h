#pragma once

#include "../Address.h"
#include "../Multiplexer.h"

namespace ArduinoIO
{
	namespace Address
	{
		class MuxedAddress : public AddressBase
		{
			public:MuxedAddress(Mux4051* mux, byte muxPort);
			public:virtual void PrepareForReading();//chiama mux.set
			protected: Mux4051* _mux;
			protected: byte _port;
		};
	}
}