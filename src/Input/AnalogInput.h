#pragma once

#include "InputDevice.h"

#define DIV1023 0.0009775
namespace ArduinoIO
{
	enum ScaleType
	{
		LIN,
		POW,
		EXP,
		LOG
	};

	struct Range
	{
		float min = 0;
		float max = 1023;
		float range = 1023;
	};

	class AnalogInput : public InputDevice<float>
	{
		public: AnalogInput(AddressBase*, void(float));

		public: void SetLogicalRange(float min, float max);
		public: void SetPhysicalRange(int min, int max);
		public: void SetPullUpResistor(float);
		public: void SetScaleType(ScaleType scaleType);
		public: void UseRangeScaling();

		protected: bool ValueChanged(int, int) override;
		protected: float GetLogicalValue(int rawValue);

		protected: ScaleType _scaleType;
		protected: Range _logicalRange;
		protected: Range _physicalRange;
		protected: float _scalingRatio;
	};
}
