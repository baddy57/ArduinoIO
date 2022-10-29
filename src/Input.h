#pragma once

#include "Input/AnalogInput.h"
#include "Input/DigitalInput.h"
#include "Input/InputDevice.h"

namespace ArduinoIO
{
	typedef AnalogInput Fader;
	typedef AnalogInput Potentiometer;
	typedef DigitalInput Button;
	typedef DigitalInput Switch;

	class MidiLinearPot : public AnalogInput
	{
		public: MidiLinearPot(AddressBase* address, void callback(float)) : AnalogInput(address, callback)
		{
			SetLogicalRange(0, 127);
			UseRangeScaling();
		}
	};
}