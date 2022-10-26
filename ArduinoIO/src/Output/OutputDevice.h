#pragma once

namespace ArduinoIO
{
	class OutputDeviceBase
	{
	};

	template <class T>
	class OutputDevice : public OutputDeviceBase
	{
		protected: virtual void Write(T) = 0;
		protected: int _address;
		protected: bool _wasUpdated;
		public: OutputDevice() = delete;
		public:	OutputDevice(int pin) : _address(pin), _wasUpdated(true) {};
	};
}