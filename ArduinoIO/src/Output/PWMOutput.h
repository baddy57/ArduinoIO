#pragma once
#include "OutputDevice.h"

namespace IO
{
	class PwmOutput : public OutputDevice<int>
	{
		public: void Write(int);
	};
}