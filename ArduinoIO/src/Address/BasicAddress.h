#pragma once
#pragma once

namespace IO
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