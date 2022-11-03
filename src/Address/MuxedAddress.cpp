#include "MuxedAddress.h"

using namespace ArduinoIO;

MuxedAddress::MuxedAddress(MultiplexerBase* mux, byte muxPort) : AddressBase()
{
	_mux = mux;
	_port = muxPort;
}

void MuxedAddress::PrepareForReading()const
{
	_mux->Prepare(_port);
}

int16_t MuxedAddress::ReadInt() const
{
	PrepareForReading();
	return _mux->ReadInt();
}

bool MuxedAddress::ReadBool() const
{
	PrepareForReading();
	return _mux->ReadBool();
}