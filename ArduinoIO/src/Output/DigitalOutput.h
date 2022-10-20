#pragma once

#include "OutputDevice.h"

namespace IO
{
	class DigitalOutput : public OutputDevice<bool>
	{
		public: void Write(bool);
		public: DigitalOutput(int);
		public: void turnOn();
	};
}