#include "DirectPinAddress.h"

using namespace ArduinoIO::Address;

DirectPinAddress::DirectPinAddress(Pin pin)
{
	_pin = pin;
}

void DirectPinAddress::PrepareForReading()
{
}