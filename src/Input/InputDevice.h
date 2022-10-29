#pragma once

#include "../Address.h"

namespace ArduinoIO
{
	enum ScaleType
	{
		LIN,
		POW,
		EXP,
		LOG
	};

	template <class T>
	struct Range
	{
		T min = 0;
		T max = 1023;
		T range = 1023;
	};

	class InputDeviceBase
	{
		public: virtual void Evaluate() = 0;
		public: AddressBase* _address;
		protected: Range<int> _physicalRange;
		protected: int oldRawValue;
		protected: int* (*ReadFn)(AddressBase*, int);

		protected: int _readAttempts;
		protected: bool ValueChanged(int, int);
	};

	template <class T>
	class InputDevice : public InputDeviceBase
	{
		public: InputDevice(AddressBase* address, void handleValueChanged(T), int readFn(AddressBase*, int*))
		{
			HandleValueChanged = handleValueChanged;
			ReadFn = readFn;
			_address = address;
		}

		public: void Evaluate();
		public: void SetLogicalRange(T min, T max);
		public: void SetPhysicalRange(int min, int max);
		public: void SetScaleType(ScaleType scaleType);
		public: void UseScaling();

		protected: void SetPullUpResistor(float);
		protected: ScaleType _scaleType = ScaleType::LIN;
		protected: Range<T>* _logicalRange;
		protected: T _scalingRatio;
		protected: T GetLogicalValue(int rawValue);
		protected: void (*HandleValueChanged)(T);
	};
}