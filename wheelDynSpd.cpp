#include "wheelDynSpd.h"
#include "wheelRegs.h"
#include "avr-api/USART.h"

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
	USART0Println("_CW");
	this->status = STATUS_CW;
	analogWrite(pinCW, spd);
	analogWrite(pinACW, 0);
}


void WheelDynamicSpeed::runACW()
{
	this->status = STATUS_ACW;
	analogWrite(pinACW, spd);
	analogWrite(pinCW, 0);
}

void WheelDynamicSpeed::stop()
{
	this->status = STATUS_STOP;
	analogWrite(pinCW, 0);
	analogWrite(pinACW, 0);
}


void WheelDynamicSpeed::disable()
{
	this->status = STATUS_DISABLE;
	analogWrite(pinCW, 0);
	analogWrite(pinACW, 0);
}

