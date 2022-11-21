#include "Arduino.h"
#include "WaterSystem.h"

void WaterSystem::setAlarmState(AlarmState alarmState)
{
    this->alarmState = alarmState;
}

AlarmState WaterSystem::getAlarmState()
{
    return this->alarmState;
}