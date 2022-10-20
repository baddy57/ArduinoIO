#pragma once

#include "OutputDevice.h"

namespace ArduinoIO
{
	class DigitalOutput : public OutputDevice<bool>
	{
		public: void Write(bool);
		public: DigitalOutput(int);
		public: void turnOn();
	};
}