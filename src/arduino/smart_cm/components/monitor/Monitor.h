#ifndef __MONITOR__
#define __MONITOR__

#include "..\..\AlarmState.h"
#include "..\servoMotor\ServoMotor.h"
#include "..\sonar\Sonar.h"

class Monitor
{
public:
    virtual void init() = 0;
    virtual void clear() = 0;
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void showMessageAlarm(ServoMotor *servoMotor, Sonar *sonar) = 0;
    virtual void showMessagePreAlarm(Sonar *sonar) = 0;
};

#endif