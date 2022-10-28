#pragma once
#include <Arduino.h>

namespace ArduinoIO
{
	namespace Multiplexers
	{
		class MultiplexerBase
		{
			public: virtual void Prepare(byte port) = 0;
		};
	}
}