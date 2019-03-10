#include "wheelDynSpd.h"

void WheelDynamicSpeed::setSpeed(uint16_t spd)
{
	this->spd = spd;
}

uint16_t WheelDynamicSpeed::getSpeed()
{
	return this->spd;
}