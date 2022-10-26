#pragma once

#include "OutputDevice.h"

namespace ArduinoIO
{
	class DigitalOutput : public OutputDevice<bool>
	{
		public: DigitalOutput(int);
		public: void Write(bool);
		public: void turnOn();
	};
}