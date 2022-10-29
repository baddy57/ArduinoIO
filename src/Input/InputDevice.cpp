#include "InputDevice.h"
#include <math.h>

#define DIV_E 1 / (M_E - 1)

using namespace ArduinoIO;

bool InputDeviceBase::ValueChanged(int oldv, int newv)
{
	return oldv != newv;
}

template<class T>
void InputDevice<T>::Evaluate()
{
	int rawValue = ReadFn(_address);
	if (ValueChanged(oldRawValue, rawValue))
	{
		T value = GetLogicalValue(rawValue);
		handleValueChanged(value);
		oldRawValue = value;
	}
}