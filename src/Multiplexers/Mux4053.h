#pragma once

#include "../Address/AddressBase.h"
#include "MultiplexerBase.h"

namespace ArduinoIO
{
	class Mux4053 : public MultiplexerBase
	{
		public: Mux4053(AddressBase* address, Pin pinA, Pin pinBC);

		public: void Prepare(byte port);//chiama address. prepare

		protected: AddressBase* _address;
		protected: Pin _pinA, _pinBC;
	};
}