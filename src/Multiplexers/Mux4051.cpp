#include "Mux4051.h"

using namespace ArduinoIO;

Mux4051::Mux4051(AddressBase* address, pin pinA, pin pinB, pin pinC) : MultiplexerBase(address)
{
	_pinA = pinA;
	_pinB = pinB;
	_pinC = pinC;
}

void Mux4051::Prepare(byte port) const
{
	MultiplexerBase::Prepare(port);
	digitalWrite(_pinA, port % 8);
	digitalWrite(_pinB, port % 4);
	digitalWrite(_pinC, port % 2);
}