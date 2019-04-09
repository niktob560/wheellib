#include "wheelEmpty.h"
#include "wheelRegs.h"
void WheelEmpty::setSpeed(uint16_t spd)
{
  this->spd = spd;
}
uint16_t WheelEmpty::getSpeed()
{
  return this->spd;
}
//just empty
void WheelEmpty::runCW()//run wheel clockwise
{
  this->status = STATUS_CW;
}
void WheelEmpty::runACW()//run wheel anti-clockwise
{
  this->status = STATUS_ACW;
}
void WheelEmpty::stop()//stop wheel
{
  this->status = STATUS_STOP;
}
void WheelEmpty::disable()//stop wheel, but powersaving
{
  this->status = STATUS_DISABLE;
}
