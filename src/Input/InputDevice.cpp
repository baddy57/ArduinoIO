#include "InputDevice.h"
using namespace ArduinoIO;

template<class T>
T InputDevice<T>::GetLogicalValue(int rawValue)
{
	return T();
}
template<class T>

void InputDevice<T>::Evaluate()
{
	int rawValue = _address->ReadInt();
	if (oldRawValue != rawValue)
	{
		T value = GetLogicalValue(rawValue);
		handleValueChanged(value);
		oldRawValue = value;
	}
}