#include "Mux4051.h"

using namespace ArduinoIO::Multiplexer;

Mux4051::Mux4051(BasicAddress* address, Pin pinA, Pin pinB, Pin pinC)
{
	_pinA = pinA;
	_pinB = pinB;
	_pinC = pinC;
	_address = address;
}

void Mux4051::Prepare(byte port)
{
	_address->PrepareForReading();
	digitalWrite(_pinA, port % 8);
	digitalWrite(_pinB, port % 4);
	digitalWrite(_pinC, port % 2);
}