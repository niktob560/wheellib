#pragma once

#include <stdint.h>
#include "wheel.h"
#include "platformRegs.h"


class Platform
{
private:
	Wheel ** wheels = 0;
	uint8_t numOfWheels;
	uint8_t wheelAdded;
	uint8_t templ;
	uint8_t status;
	uint16_t error;
	uint16_t spd = 0;

public:
	//constructors:
	Platform(uint8_t templ);


	//setters:
	void setNumOfWheels(uint8_t num);
	void setTemplate(uint8_t t);
	void setStatus(uint8_t status);
	void setSpeed(uint16_t spd);


	//getters:
	uint8_t getNumOfWheels();
	uint8_t getTemplate();
	uint8_t getStatus();
	uint16_t getError();
	uint16_t getSpeed();
	Wheel* getWheel(uint8_t _i);


	//etc:
	uint8_t addWheel(Wheel* wh);
	void runForward();
	void runBackward();
	void runRight();
	void runLeft();
	void turnCW();
	void turnACW();
	void runFwdRight();//run forward and right
	void runFwdLeft();//run forward and left
	void runBckRight();//run backward and right
	void runBckLeft();//run backward and left
	void strafe(int16_t angle);
	void stop();
	void powerSave();
};