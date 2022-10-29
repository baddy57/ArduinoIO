#include "DirectPinAddress.h"

using namespace ArduinoIO;

DirectPinAddress::DirectPinAddress(Pin pin)
{
	_pin = pin;
}

void DirectPinAddress::PrepareForReading()
{
}