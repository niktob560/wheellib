#include "wheel.h"

class WheelEmpty : public Wheel
{
private:
  uint16_t spd = 0;
public:
  void setSpeed(uint16_t spd);
	uint16_t getSpeed();
  void runCW();//run wheel clockwise
  void runACW();//run wheel anti-clockwise
  void stop();//stop wheel
  void disable();//stop wheel, but powersaving
};
