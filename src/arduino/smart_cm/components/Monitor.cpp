#include "Arduino.h"
#include "Monitor.h"

#include "AlarmState.h"

void Monitor::showMessage()
{
    AlarmState alarmState = AlarmState::NORMAL_SITUATION;
    if (alarmState == AlarmState::PRE_ALARM_SITUATION)
    {
    }
    else if (alarmState == AlarmState::ALARM_SITUATION)
    {
    }
}