#pragma once

#include "wheel.h"
#include "wheelRegs.h"

#include <avr/io.h>						//include for base avr funcs
#define F_CPU 16000000       		   	//define with freq
#include <util/delay.h>					//include for delay func
#include <avr/interrupt.h>   		   	//include interrupt funcs
#include <stdlib.h>
#include "errorCodes.h"

#include "avr-api/digitalRegisters.h"


Wheel::Wheel(){}
Wheel::Wheel(uint8_t type)
{
	this->type = type;
}


void Wheel::setStatus(uint8_t newStatus)
{
	this->status = newStatus;

	switch(status)
	{
		case STATUS_STOP:
		{
			this->stop();
			break;
		}
		case STATUS_DISABLE:
		{
			this->disable();
			break;
		}
		case STATUS_CW:
		{
			this->runCW();
			break;
		}
		case STATUS_ACW:
		{
			this->runACW();
			break;
		}
	}
}

void Wheel::setType(uint8_t newType)
{
	this->type = newType;
}

void Wheel::setPinCW(uint16_t pinCW)
{
	this->pinCW = pinCW;
}

void Wheel::setPinACW(uint16_t pinACW)
{
	this->pinACW = pinACW;
}

void Wheel::setPlacement(uint8_t placement)
{
	this->placement = placement;
}



uint8_t Wheel::getStatus()
{
	return this->status;
}

uint8_t Wheel::getType()
{
	return this->type;
}

uint16_t Wheel::getPinCW()
{
	return this->pinCW;
}

uint16_t Wheel::getPinACW()
{
	return this->pinCW;
}

uint8_t Wheel::getPlacement()
{
	return placement;
}



void Wheel::runCW()
{
	digitalWrite(this->pinCW, HIGH);//enable CW
	digitalWrite(this->pinACW, LOW);//disable ACW
}

void Wheel::runACW()
{
	digitalWrite(this->pinCW, LOW);//disable CW
	digitalWrite(this->pinACW, HIGH);//enable CW
}

void Wheel::stop()
{
	digitalWrite(this->pinCW, HIGH);//enable CW
	digitalWrite(this->pinACW, HIGH);//enable CW	
}

void Wheel::disable()
{
	digitalWrite(this->pinCW, LOW);//disable CW
	digitalWrite(this->pinACW, LOW);//disable ACW
}

