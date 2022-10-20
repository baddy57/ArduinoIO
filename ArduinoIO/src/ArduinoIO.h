/*
 Name:		ArduinoIO.h
 Created:	2022-10-20 23:14:33
 Author:	cristian
 Editor:	http://www.visualmicro.com
*/

#pragma once

#include "Input/AnalogInput.h"
#include "Input/DigitalInput.h"
#include "Output/DigitalOutput.h"

namespace IO
{
	typedef AnalogInput Fader;
	typedef AnalogInput Potentiometer;
	typedef DigitalInput Button;
	typedef DigitalInput Switch;

	typedef DigitalOutput Led;
}