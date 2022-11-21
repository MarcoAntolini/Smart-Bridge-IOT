#include "ServoMotorImpl.h"

void ServoMotorImpl::open(int angle)
{
    this->angle = angle;
}

void ServoMotorImpl::close()
{
    this->angle = 0;
}

int ServoMotorImpl::getAngle()
{
    return this->angle;
}