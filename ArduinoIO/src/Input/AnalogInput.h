#pragma once

#include "InputDevice.h"

#define DIV1023 0.0009775
namespace ArduinoIO
{
	enum ScaleType
	{
		LIN, EXP, LOG, POW
	};

	class AnalogInput : public InputDevice<int>
	{
		public: AnalogInput(BasicAddress* _address, void callback(int));

		/*inherited
		ControlAddress _address
		bool _wasUpdated; */
		//private: float value = -10.f;
		private: float minRead = 0.f, maxRead = 1023.f;
		private: float rangeScope = 0;
		private: float rangeMin = 0.f;
		private: float rangeMax = 0.f;
		private: float range = 1.f;
		private: float k = 1;
		private: int scale = LIN;

		/// @brief constructor
		/// @param a _address of the module
		/// @param id pin on the module pcb
		/// @param pullup_res value of the pullup resistor
		//AnalogInput(const Address& a, uint_fast8_t id, float pullup_res = 0.f) : InputDevice(a, id), value(0) { setPullUpResistor(pullup_res); };

		// /// @brief set the value of the pullup to fix readings
		// /// @param value of the pullup resistor in ohm
		//public: void setPullUpResistor(float);

		///// @brief set the target range of the reading
		///// @param min value
		///// @param max value
		///// @param flag LIN,LOG,EXP,POW
		//public: void setRange(float, float, int flag = LIN);

		/// @brief translates the hardware value into target value
		/// @return a value from the range set before
		public: void read();
	};
}
