#include "wheel.h"

class WheelEmpty : public Wheel
{
private:
public:
  void setSpeed(uint16_t spd);
  void runCW();//run wheel clockwise
  void runACW();//run wheel anti-clockwise
  void stop();//stop wheel
  void disable();//stop wheel, but powersaving

}
