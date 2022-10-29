#include "AnalogInput.h"
#include <math.h>

using namespace ArduinoIO;
extern const float POT_DEADZONE;

extern const int POT_READS;

static int ReadInt_AvgFilter(AddressBase* a, int attempts)
{
	int* temp = new int[attempts];
	float sum = 0;
	for (int i = 0; i < attempts; ++i)
	{
		sum += a->ReadInt();
	}
	return sum / attempts;
}

template <class T>
AnalogInput<T>::AnalogInput(AddressBase* address, void callback(int))
	: InputDevice<T>(address, callback, ReadInt_AvgFilter)
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
//			_scalingRatio = (_max - _min) / 1023.f;
//			break;
//		case EXP:
//			_scalingRatio = 1 / 1023.f;
//			break;
//	}
//}

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