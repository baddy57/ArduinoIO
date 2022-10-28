#pragma once

#include "AddressBase.h"
#include "../Multiplexers/MultiplexerBase.h"

namespace ArduinoIO
{
	namespace Address
	{
		class MuxedAddress : public AddressBase
		{
			public:MuxedAddress(Multiplexers::MultiplexerBase* mux, int muxPort);
			public:virtual void PrepareForReading();//chiama mux.set
			protected: Multiplexers::MultiplexerBase* _mux;
			protected: byte _port;
		};
	}
}