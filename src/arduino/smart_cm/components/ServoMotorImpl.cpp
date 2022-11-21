#include "Arduino.h"
#include "ServoMotorImpl.h"

ServoMotorImpl::ServoMotorImpl(uint8_t pin) : ServoMotor(pin)
{
    this->angle = 0;
}

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