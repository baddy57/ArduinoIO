/*
 Name:		ArduinoIO.h
 Created:	2022-10-20 23:14:33
 Author:	cristian
 Editor:	http://www.visualmicro.com
*/

#pragma once

#include "src/Address.h"
#include "src/Multiplexer.h"
#include "src/Input.h"
#include "src/Output.h"

namespace ArduinoIO
{
	typedef AnalogInput Fader;
	typedef AnalogInput Potentiometer;
	typedef DigitalInput Button;
	typedef DigitalInput Switch;

	typedef DigitalOutput Led;
}