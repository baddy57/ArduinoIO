#pragma once

#include "AddressBase.h"
#include "../Multiplexers/MultiplexerBase.h"

namespace ArduinoIO
{
	class MuxedAddress : public AddressBase
	{
		public:MuxedAddress(MultiplexerBase* mux, int muxPort);
		public:virtual void PrepareForReading();//chiama mux.set
		protected: MultiplexerBase* _mux;
		protected: byte _port;
	};
}