#ifndef __MONITORIMPL__
#define __MONITORIMPL__

#include "Monitor.h"
#include "LiquidCrystal_I2C.h"

class MonitorImpl : public Monitor
{
public:
    MonitorImpl(uint8_t addr, uint8_t cols, uint8_t rows);
    void init();
    void clear();
    void turnOn();
    void turnOff();
    void showMessageAlarm(ServoMotor *servoMotor, Sonar *sonar);
    void showMessagePreAlarm(Sonar *sonar);

private:
    LiquidCrystal_I2C *lcd;
};

#endif