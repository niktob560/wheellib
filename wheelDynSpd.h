#include "wheel.h"
#include "avr-api/Timers.h"
class WheelDynamicSpeed : public Wheel
{
private:
	uint16_t spd = 0;
	void (*speedHook)(uint16_t) = 0x00;
public:
	void setSpeed(uint16_t);
	uint16_t getSpeed();
	void runCW();
	void runACW();
	void stop();
	void disable();
	void installSpeedHook(void (*hook)(uint16_t));
	void removeSpeedHook();
};
