#include "DirectPinAddress.h"

using namespace ArduinoIO;

DirectPinAddress::DirectPinAddress(pin pin)
{
	_pin = pin;
}

int16_t DirectPinAddress::ReadInt() const
{
	return analogRead(_pin);
}

bool DirectPinAddress::ReadBool() const
{
	return digitalRead(_pin);
}