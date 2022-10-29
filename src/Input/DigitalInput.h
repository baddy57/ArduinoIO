#pragma once

#define BOUNCE_DELAY 20
#define DOUBLE_TAP_DELAY 100
#define LONG_PRESS_TIME 500

#include "InputDevice.h"

namespace ArduinoIO
{
	class DigitalInput : public InputDevice<bool>
	{
		public: DigitalInput(AddressBase*, void(bool));
		protected: bool doubleTapDetected = false;

		//public: virtual bool tap();
		//public: bool longPress();
		//public: void update();
		//public: bool isPressed();
	};
}