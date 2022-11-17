#include "Arduino.h"
#include "MonitorImpl.h"

#include "AlarmState.h"

void MonitorImpl::showMessage()
{
    AlarmState alarmState = AlarmState::NORMAL_SITUATION;
    if (alarmState == AlarmState::PRE_ALARM_SITUATION)
    {
    }
    else if (alarmState == AlarmState::ALARM_SITUATION)
    {
    }
}