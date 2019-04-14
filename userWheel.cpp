#include "userWheel.h"
#include "wheelRegs.h"
void WheelUser::setSpeed(uint16_t spd)
{
  this->spd = spd;
  if(speedHook != 0x00)
    speedHook(spd);
}
uint16_t WheelUser::getSpeed()
{
  return this->spd;
}
//just empty
void WheelUser::runCW()//run wheel clockwise
{
  this->status = STATUS_CW;
  if(*runCWHook != 0x00)
    runCWHook();
}
void WheelUser::runACW()//run wheel anti-clockwise
{
  this->status = STATUS_ACW;
  if(*runACWHook != 0x00)
    runACWHook();
}
void WheelUser::stop()//stop wheel
{
  this->status = STATUS_STOP;
  if(*stopHook != 0x00)
    stopHook();
}
void WheelUser::disable()//stop wheel, but powersaving
{
  this->status = STATUS_DISABLE;
}

void WheelUser::installCWHook(void(*hook)())
{
    runCWHook = hook;
}
void WheelUser::installACWHook(void(*hook)())
{
    runACWHook = hook;
}
void WheelUser::installStopHook(void(*hook)())
{
    stopHook = hook;
}
void WheelUser::installSpeedHook(void(*hook)(uint16_t))
{
    speedHook = hook;
}
