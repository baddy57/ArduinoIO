#pragma once
#include "OutputDevice.h"

namespace ArduinoIO
{
	class PwmOutput : public OutputDevice<int>
	{
		public: void Write(int);
	};
}