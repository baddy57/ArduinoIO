#pragma once
#include <Arduino.h>

namespace ArduinoIO
{
	class MultiplexerBase
	{
		public: virtual void Prepare(byte port) = 0;
	};
}