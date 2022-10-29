#pragma once

#include "AddressBase.h"
#include "../Multiplexers/MultiplexerBase.h"

namespace ArduinoIO
{
	class MuxedAddress : public AddressBase
	{
		public:MuxedAddress(MultiplexerBase* mux, int muxPort);

		protected: void PrepareForReading();
		protected: int ReadInt();
		protected: bool ReadBool();

		protected: MultiplexerBase* _mux;
		protected: byte _port;
	};
}