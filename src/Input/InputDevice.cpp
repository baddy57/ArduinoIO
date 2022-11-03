#include "InputDevice.h"
#include <math.h>

#define DIV_E 1 / (M_E - 1)

using namespace ArduinoIO;

bool InputDeviceBase::ValueChanged(int16_t oldv, int16_t newv)
{
	return oldv != newv;
}