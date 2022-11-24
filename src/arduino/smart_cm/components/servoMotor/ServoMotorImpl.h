#ifndef __SERVOMOTORIMPL__
#define __SERVOMOTORIMPL__

#include "ServoMotor.h"
#include <Servo.h>

class ServoMotorImpl : public ServoMotor, public Servo
{
public:
    ServoMotorImpl(uint8_t pin) : ServoMotor(pin)
    {
        this->attach(pin);
        this->angle = 0;
    };
    void open(int angle);
    void close();
    int getAngle();

private:
    int angle;
};

#endif