#include "wheelDynSpd.h"

void WheelDynamicSpeed::setSpeed(uint16_t spd)
{
	this->spd = spd;
}

uint16_t WheelDynamicSpeed::getSpeed()
{
	return this->spd;
}

void WheelDynamicSpeed::runCW()
{
	analogWrite(pinCW, spd);
	analogWrite(pinACW, 0);
}


void WheelDynamicSpeed::runACW()
{
	analogWrite(pinACW, spd);
	analogWrite(pinCW, 0);
}

void WheelDynamicSpeed::stop()
{
	analogWrite(pinCW, spd);
	analogWrite(pinACW, spd);
}


void WheelDynamicSpeed::disable()
{
	analogWrite(pinCW, 0);
	analogWrite(pinACW, 0);
}

