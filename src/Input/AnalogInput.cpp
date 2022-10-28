#include "AnalogInput.h"
#include <math.h>

using namespace ArduinoIO;
extern const float POT_DEADZONE;

extern const int POT_READS;

AnalogInput::AnalogInput(AddressBase* address, void callback(int)) : InputDevice(address, callback)
{
}

//void AnalogInput::setPullUpResistor(float pullup)
//{
//	if (pullup == 0.f)return;
//	minRead = pullup / 9.78f;
//	range = 1023.f / (990.f - minRead);
//	return;
//}
//
//void AnalogInput::setRange(float _min, float _max, int flag)
//{
//	scale = flag;
//	rangeMin = _min;
//	rangeMax = _max;
//	rangeScope = _max - _min;
//
//	switch (scale)
//	{
//		case LIN:
//			k = (_max - _min) / 1023.f;
//			break;
//		case EXP:
//			k = 1 / 1023.f;
//			break;
//	}
//}

void AnalogInput::read()
{
	//switch (scale)
	//{
	//	case LIN:
	//		return value * k + rangeMin;// / 1023.f * (max - rangeMin) + rangeMin;
	//	case EXP:
	//		return (exp(value * k) - 1) * rangeScope / (M_E - 1) + rangeMin;
	//	case LOG:
	//		return 0;
	//	case POW:
	//		return 0;// pow(2, (uint)value / 8) / pow(2, 127) * (max - rangeMin) + rangeMin;
	//	default:
	//		return -1;
	//}
}

//void
//AnalogInput::update()
//{
//	//_address.setForReading();
//	int r_sum = 0;
//
//	for (int i = 0; i < POT_READS; ++i)
//		r_sum += analogRead(_address);
//
//	float avg = r_sum / POT_READS;
//	avg -= minRead;
//	avg *= range;
//	if (avg < 2.f) avg = 0.f;
//	if (avg > 1020.f) avg = 1023.f;
//
//	if (avg > value + POT_DEADZONE || avg < value - POT_DEADZONE)
//	{
//		value = avg;
//		_wasUpdated = true;
//		return;
//	}
//	else //if the value is the same as before
//		_wasUpdated = false;
//	return;
//}