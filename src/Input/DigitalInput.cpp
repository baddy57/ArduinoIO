#include "DigitalInput.h"

using namespace ArduinoIO;

int16_t ReadBool(AddressBase* a)
{
	return a->ReadBool();
}
//ctor
DigitalInput::DigitalInput(AddressBase* address, void callback(bool))
	: InputDevice(address, callback, ReadBool)
{
}

//bool DigitalInput::longPress()
//{
//	if (wasUpdated() && state)
//	{
//		int counter = LONG_PRESS_TIME;
//		while (counter > 0)
//		{
//			if (!isPressed())
//				return false;
//			counter -= BOUNCE_DELAY;
//		}
//		return true;
//	}
//	return false;
//}