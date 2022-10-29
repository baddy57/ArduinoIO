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
	int rawValue = ReadFn(_address);//todo fixme sto facendo sempre analog
	if (oldRawValue != rawValue)
	{
		T value = GetLogicalValue(rawValue);
		handleValueChanged(value);
		oldRawValue = value;
	}
}