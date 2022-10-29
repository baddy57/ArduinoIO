#include "DirectPinAddress.h"

using namespace ArduinoIO;

DirectPinAddress::DirectPinAddress(Pin pin)
{
	_pin = pin;
}

void DirectPinAddress::PrepareForReading()
{
}

int DirectPinAddress::ReadInt()
{
	return analogRead(_pin);
}

bool DirectPinAddress::ReadBool()
{
	return digitalRead(_pin);
}