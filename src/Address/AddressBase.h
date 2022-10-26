#pragma once

namespace ArduinoIO
{
	namespace Address
	{
		class AddressBase
		{
			public:virtual void PrepareForReading() = 0;
		};
	}
}