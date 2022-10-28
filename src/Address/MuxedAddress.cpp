#include "MuxedAddress.h"

using namespace ArduinoIO::Address;
using namespace ArduinoIO::Multiplexers;

MuxedAddress::MuxedAddress(MultiplexerBase* mux, byte muxPort) : AddressBase()
{
	_mux = mux;
	_port = muxPort;
}

void MuxedAddress::PrepareForReading()
{
	_mux->Prepare(_port);
}