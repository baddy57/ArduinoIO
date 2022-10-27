#include "Mux4053.h"
#include "../Address/AddressBase.h"

using namespace ArduinoIO::Multiplexer;
using namespace ArduinoIO::Address;

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