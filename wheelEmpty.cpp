#include "wheelEmpty.h"

void WheelEmpty::setSpeed(uint16_t spd)
{
  this->spd = spd;
}
//just empty
void WheelEmpty::runCW(){}//run wheel clockwise
void WheelEmpty::runACW(){}//run wheel anti-clockwise
void WheelEmpty::stop(){}//stop wheel
void WheelEmpty::disable(){}//stop wheel, but powersaving
