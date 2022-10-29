#include "InputDevice.h"
#include <math.h>

#define DIV_E 1 / (M_E - 1)
#define POT_DEADZONE 3

using namespace ArduinoIO;

bool InputDeviceBase::ValueChanged(int oldv, int newv)
{
	bool x = fdim(oldv, newv);
	return x > POT_DEADZONE;
}

template<class T>
T InputDevice<T>::GetLogicalValue(int rawValue)
{
	switch (_scaleType)
	{
		case LIN:
			return rawValue * _scalingRatio + _logicalRange.min;
		case EXP:
			return (exp(rawValue * _scalingRatio) - 1) * (_logicalRange.range) * DIV_E + _logicalRange.min;
		//case LOG:
		//	return 0;
		//case POW:
		//	return 0;// pow(2, (uint)value / 8) / pow(2, 127) * (max - rangeMin) + rangeMin;
		default:
			return -1;
	}
	return T();
}

template<class T>
void InputDevice<T>::Evaluate()
{
	int rawValue[_readAttempts] = ReadFn(_address, _readAttempts);
	if (ValueChanged(oldRawValue, rawValue))
	{
		T value = GetLogicalValue(*rawValue);
		handleValueChanged(value);
		oldRawValue = value;
	}
}

template<class T>
void InputDevice<T>::SetLogicalRange(T min, T max)
{
	_logicalRange.min = min;
	_logicalRange.max = max;
	_logicalRange.range = max - min;
}

template<class T>
void InputDevice<T>::SetPullUpResistor(float pullup)
{
	if (pullup == 0.f)return;
	_physicalRange.min = pullup / 9.78f;
	_physicalRange.range = 1023.f / (990.f - _physicalRange.min);
	_physicalRange.max = _physicalRange.min + _physicalRange.range;
	return;
}

template<class T>
void InputDevice<T>::SetPhysicalRange(int min, int max)
{
	_physicalRange.min = min;
	_physicalRange.max = max;
	_physicalRange.range = max - min;
}

template<class T>
void ArduinoIO::InputDevice<T>::SetScaleType(ScaleType scaleType)
{
	_scaleType = scaleType;
}

template<class T>
void ArduinoIO::InputDevice<T>::UseScaling()
{
	switch (_scaleType)
	{
		case LIN:
			_scalingRatio = (_logicalRange.range) / (_physicalRange.range);
			break;
		case EXP:
			_scalingRatio = 1.f / (_physicalRange.range);
			break;
		default:
			break;
	}
}