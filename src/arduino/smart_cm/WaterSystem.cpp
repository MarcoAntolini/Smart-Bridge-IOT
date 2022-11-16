#include "Arduino.h"
#include "WaterSystem.h"

// costruttore

void WaterSystem::setAlarmState(AlarmState alarmState)
{
    this->alarmState = alarmState;
}

AlarmState WaterSystem::getAlarmState()
{
    return this->alarmState;
}