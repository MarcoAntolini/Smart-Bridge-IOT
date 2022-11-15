#include "Arduino.h"
#include "Monitor.h"

#include "AlarmState.h"

Monitor::Monitor(int pin)
{
    this->pin = pin;
    pinMode(pin, OUTPUT);
}

void Monitor::showMessage()
{
    AlarmState alarmState = AlarmState::NORMAL_SITUATION;
    switch (alarmState)
    {
    case AlarmState::NORMAL_SITUATION:

        break;
    case AlarmState::ALARM_SITUATION:

        break;
    case AlarmState::PRE_ALARM_SITUATION:

        break;
    default:
        break;
    }
}