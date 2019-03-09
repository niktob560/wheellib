#pragma once

#include <stdint.h>
#include "wheel.h"


class Platform
{
private:
	Wheel ** wheels = 0;
	uint8_t numOfWheels;
	uint8_t wheelAdded;
	uint8_t templ;
	uint8_t status;
	uint16_t error;

public:
	//constructors:
	Platform(uint8_t templ);


	//setters:
	void setNumOfWheels(uint8_t num);
	void setTemplate(uint8_t t);
	void setStatus(uint8_t status);


	//getters:
	uint8_t getNumOfWheels();
	uint8_t getTemplate();
	uint8_t getStatus();
	uint8_t getError();


	//etc:
	uint8_t addWheel(Wheel* wh);
	void runFoward();
	void runBackward();
	void runRight();
	void runLeft();
	void turnCW();
	void turnACW();
	void stop();
	void powerSave();
};