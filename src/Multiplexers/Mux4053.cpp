#include "Mux4053.h"

using namespace ArduinoIO;

Mux4053::Mux4053(AddressBase* address, Pin pinA, Pin pinBC)
{
	_address = address;
	_pinA = pinA;
	_pinBC = pinBC;
}

void Mux4053::Prepare(byte port)
{
	_address->PrepareForReading();
	digitalWrite(_pinA, port % 4);
	digitalWrite(_pinBC, port % 2);
}