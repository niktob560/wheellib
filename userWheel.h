#include "wheel.h"

class WheelUser : public Wheel
{
private:
    uint16_t spd = 0;
    void (*speedHook)(uint16_t) = 0x00;
    void (*runCWHook)() = 0x00;
    void (*runACWHook)() = 0x00;
    void (*stopHook)() = 0x00;
public:
    void setSpeed(uint16_t spd);
	uint16_t getSpeed();
    void runCW();//run wheel clockwise
    void runACW();//run wheel anti-clockwise
    void stop();//stop wheel
    void disable();//stop wheel, but powersaving

    void installSpeedHook(void(*hook)(uint16_t));
    void installCWHook(void(*hook)());
    void installACWHook(void(*hook)());
    void installStopHook(void(*hook)());
};
