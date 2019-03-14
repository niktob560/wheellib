#pragma once

#include <stdint.h>

class Wheel
{
protected:
	uint8_t type;
	uint8_t status;
	uint16_t pinCW;
	uint16_t pinACW;
	uint8_t placement;
public:
	//constructors:
	Wheel();
	Wheel(uint8_t type);

	//setters:
	void setStatus(uint8_t newStatus);
	void setType(uint8_t newType);
	void setPinCW(uint16_t pinCW);
	void setPinACW(uint16_t pinACW);
	void setPlacement(uint8_t placement);
	virtual void setSpeed(uint16_t spd);


	virtual void runCW();//run wheel clockwise
	virtual void runACW();//run wheel anti-clockwise
	virtual void stop();//stop wheel
	virtual void disable();//stop wheel, but powersaving


	//getters:
	uint8_t getStatus();
	uint8_t getType();
	uint16_t getPinCW();
	uint16_t getPinACW();
	uint8_t getPlacement();
};