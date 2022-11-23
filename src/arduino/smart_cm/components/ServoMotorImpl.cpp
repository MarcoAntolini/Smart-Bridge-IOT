#include "ServoMotorImpl.h"

void ServoMotorImpl::open(int angle)
{
    this->angle = angle;
    this->write(angle);
}

void ServoMotorImpl::close()
{
    this->angle = 0;
    this->write(angle);
}

int ServoMotorImpl::getAngle()
{
    return this->angle;
}