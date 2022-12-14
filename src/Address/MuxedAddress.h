#pragma once

#include "AddressBase.h"
#include "../Multiplexers/MultiplexerBase.h"

namespace ArduinoIO
{
	class MuxedAddress : public AddressBase
	{
		public:MuxedAddress(MultiplexerBase* mux, byte muxPort);

		public: void PrepareForReading() const override;
		public: int16_t ReadInt() const;
		public: bool ReadBool() const;
		public: pin GetPin() const { return _mux->_address->GetPin(); }

		protected: MultiplexerBase* _mux;
		protected: byte _port;
	};
}