#pragma once

namespace Arduino
{
	namespace Multiplexer
	{
		class Multiplexer
		{
			public: virtual void Prepare(byte port) = 0;
		};
	}
}