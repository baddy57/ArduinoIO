#include "MuxedAddress.h"

using namespace ArduinoIO;

MuxedAddress::MuxedAddress(MultiplexerBase* mux, int muxPort) : AddressBase()
{
	_mux = mux;
	_port = muxPort;
}

void MuxedAddress::PrepareForReading()
{
	_mux->Prepare(_port);
}

int MuxedAddress::ReadInt()
{
	return _mux->ReadInt();
}

bool MuxedAddress::ReadBool()
{
	return _mux->ReadBool();
}