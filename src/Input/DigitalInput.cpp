#include "DigitalInput.h"

using namespace ArduinoIO;

//ctor
DigitalInput::DigitalInput(BasicAddress* address, void callback(bool)) : InputDevice(_address, callback)
{
	value = false;
}

void DigitalInput::read()
{
	//todo
}

//bool DigitalInput::tap()
//{
//	if (wasUpdated() && state)
//	{
//		delay(BOUNCE_DELAY);
//		if (!isPressed())
//			return true;
//	}
//	return false;
//}
//
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
//
//bool
//DigitalInput::isPressed()
//{
//	update();
//	return state;
//}
//
//void
//DigitalInput::update()
//{
//	bool r = !digitalRead(_address);
//	if (r != state)
//	{
//		state = r;
//		_wasUpdated = true;
//	}
//	else
//		_wasUpdated = false;
//}