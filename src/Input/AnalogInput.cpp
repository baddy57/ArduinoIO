#include "AnalogInput.h"
#include <math.h>

#define DIV_E 1 / (M_E - 1)
#define POT_DEADZONE 3
#define READ_ATTEMPTS 3

using namespace ArduinoIO;

static int16_t ReadInt_AvgFilter(AddressBase* a)
{
	int16_t temp[READ_ATTEMPTS];
	float sum = 0;
	for (int16_t i = 0; i < READ_ATTEMPTS; ++i)
	{
		sum += a->ReadInt(); //todo fixme preparazione va fatta una volta sola
	}
	return sum / READ_ATTEMPTS;
}

float AnalogInput::GetLogicalValue(int16_t rawValue)
{
	switch (_scaleType)
	{
		case LIN:
			return (rawValue - _physicalRange.min) * _scalingRatio + _logicalRange.min;
		case EXP:
			return (exp((rawValue - _physicalRange.min) * _scalingRatio) - 1) * (_logicalRange.range) * DIV_E + _logicalRange.min;
		//case LOG:
		//	return 0;
		//case POW:
		//	return 0;// pow(2, (uint)value / 8) / pow(2, 127) * (max - rangeMin) + rangeMin;
		default:
			return -1;
	}
	return -1;
}

AnalogInput::AnalogInput(AddressBase* address, void callback(float))
	: InputDevice(address, callback, ReadInt_AvgFilter)
{
	_scaleType = ScaleType::LIN;
	_scalingRatio = 1;
}

bool AnalogInput::ValueChanged(int16_t oldv, int16_t newv)
{
	int16_t delta = oldv > newv ? oldv - newv : newv - oldv;
	return delta > POT_DEADZONE;
}

void AnalogInput::SetLogicalRange(float min, float max)
{
	_logicalRange.min = min;
	_logicalRange.max = max;
	_logicalRange.range = max - min;
}

void AnalogInput::SetPullUpResistor(float pullup)
{
	if (pullup == 0.f)return;
	_physicalRange.min = pullup / 9.78f;
	_physicalRange.range = 1023.f / (990.f - _physicalRange.min);
	_physicalRange.max = _physicalRange.min + _physicalRange.range;
	return;
}

void AnalogInput::SetPhysicalRange(int16_t min, int16_t max)
{
	_physicalRange.min = min;
	_physicalRange.max = max;
	_physicalRange.range = max - min;
}

void AnalogInput::SetScaleType(ScaleType scaleType)
{
	_scaleType = scaleType;
}

void AnalogInput::UseRangeScaling()
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
//	if (avg < 2.f) avg = 0.f;
//	if (avg > 1020.f) avg = 1023.f;