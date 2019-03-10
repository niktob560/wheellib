#include "wheel.h"

class WheelDynamicSpeed : public Wheel
{
private:
	uint16_t spd = 0;
public:
	void setSpeed(uint16_t);
	uint16_t getSpeed();
};