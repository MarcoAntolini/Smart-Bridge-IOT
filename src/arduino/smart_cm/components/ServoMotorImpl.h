#ifndef __SERVOMOTORIMPL__
#define __SERVOMOTORIMPL__

#include "ServoMotor.h"

class ServoMotorImpl : public ServoMotor
{
public:
    ServoMotorImpl(uint8_t pin) : ServoMotor(pin){};
    void open(int angle);
    void close();
    int getAngle();

private:
    int angle;
};

#endif