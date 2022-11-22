#include "Arduino.h"
#include "WaterSystem.h"
#include "..\Config.h"

void WaterSystem::run()
{
    if (sonar->detectDistance() < waterLevel_1)
    {
        alarmState = AlarmState::NORMAL_SITUATION;
        normalTask();
    }
    else if (sonar->detectDistance() < waterLevel_2)
    {
        alarmState = AlarmState::PRE_ALARM_SITUATION;
        preAlarmTask();
    }
    else if (sonar->detectDistance() < waterLevel_max)
    {
        alarmState = AlarmState::ALARM_SITUATION;
        alarmTask();
    }
}

void WaterSystem::normalTask()
{
    if (getPeriod() != period_normal)
    {
        setPeriod(period_normal);
    }
    if (!ledB->getStatus())
    {
        digitalWrite(ledB, HIGH);
    }
    if (ledC->getStatus())
    {
        digitalWrite(ledC, LOW);
    }
}
void WaterSystem::preAlarmTask()
{
    if (getPeriod() != period_preAlarm)
    {
        setPeriod(period_preAlarm);
    }
    // TODO ledC blinking every 2s
    monitor->showMessage(alarmState, servoMotor, sonar);
}
void WaterSystem::alarmTask()
{
    if (getPeriod() != period_alarm)
    {
        setPeriod(period_alarm);
    }
    // TODO light system off if ledA is off
    if (ledB->getStatus())
    {
        digitalWrite(ledB, LOW);
    }
    if (!ledC->getStatus())
    {
        digitalWrite(ledC, HIGH);
    }
    monitor->showMessage(alarmState, servoMotor, sonar);
    // TODO motor opened according to sonar
    // TODO button activation and pot
}