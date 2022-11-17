#include "Arduino.h"
#include "ValveImpl.h"

ValveImpl::ValveImpl()
{
    this->angle = 0;
}

void ValveImpl::close()
{
    this->angle = 0;
}

void ValveImpl::open(int angle)
{
    this->angle = angle;
}

int ValveImpl::getAngle()
{
    return this->angle;
}