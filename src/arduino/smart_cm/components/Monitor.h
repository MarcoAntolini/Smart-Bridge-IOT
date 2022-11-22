#ifndef __MONITOR__
#define __MONITOR__

#include "../AlarmState.h"
#include "ServoMotor.h"
#include "Sonar.h"

class Monitor
{
public:
    virtual void init() = 0;
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void showMessage(AlarmState alarmState, ServoMotor *servoMotor, Sonar *sonar) = 0;
    virtual void clear() = 0;
};

#endif