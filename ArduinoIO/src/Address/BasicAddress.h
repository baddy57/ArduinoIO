#pragma once
#pragma once

namespace ArduinoIO
{
	namespace Address
	{
		class BasicAddress
		{
			public:BasicAddress(int pin);
			public:virtual void PrepareForReading();
			protected: int pin;
		};
	}
}