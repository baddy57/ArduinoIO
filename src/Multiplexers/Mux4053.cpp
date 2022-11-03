#include "Mux4053.h"

using namespace ArduinoIO;

Mux4053::Mux4053(AddressBase* address, Pin pinA, Pin pinBC) : MultiplexerBase(address)
{
	_pinA = pinA;
	_pinBC = pinBC;
}

void Mux4053::Prepare(byte port) const
{
	MultiplexerBase::Prepare(port);
	digitalWrite(_pinA, port % 4);
	digitalWrite(_pinBC, port % 2);
}