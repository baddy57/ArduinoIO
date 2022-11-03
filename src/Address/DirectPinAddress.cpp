#include "DirectPinAddress.h"

using namespace ArduinoIO;

DirectPinAddress::DirectPinAddress(Pin pin)
{
	_pin = pin;
}

void DirectPinAddress::PrepareForReading() const
{
}

int16_t DirectPinAddress::ReadInt() const
{
	return analogRead(_pin);
}

bool DirectPinAddress::ReadBool() const
{
	return digitalRead(_pin);
}