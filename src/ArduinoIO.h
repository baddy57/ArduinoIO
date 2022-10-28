/*
 Name:		ArduinoIO.h
 Created:	2022-10-20 23:14:33
 Author:	cristian
 Editor:	http://www.visualmicro.com
*/

#pragma once

#include "Address.h"
#include "Multiplexer.h"
#include "Input.h"
#include "Output.h"

namespace ArduinoIO
{
	typedef AnalogInput Fader;
	typedef AnalogInput Potentiometer;
	typedef DigitalInput Button;
	typedef DigitalInput Switch;

	typedef DigitalOutput Led;
}