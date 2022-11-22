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
        digitalWrite(ledB->getPin(), HIGH);
    }
    if (ledC->getStatus())
    {
        digitalWrite(ledC->getPin(), LOW);
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
    if (!lightSystem->getLed()->getStatus()) // TODO vuol dire che deve essere spenta o che la spegniamo noi?
    {
        lightSystem->setActive(false); // TODO riattivare dopo
    }
    if (ledB->getStatus())
    {
        digitalWrite(ledB->getPin(), LOW);
    }
    if (!ledC->getStatus())
    {
        digitalWrite(ledC->getPin(), HIGH);
    }
    monitor->showMessage(alarmState, servoMotor, sonar);
    servoMotor->open(map(sonar->detectDistance(), 0, maxDistance, 0, 180));
    if (!button->isEnabled())
    {
        button->setEnabled(true); // TODO disattivare dopo
    }
    else // TODO serve? è tardi scusate
    {
        if (button->isPressed())
        {
            manualMode = !manualMode;
        }
    }
    if (manualMode)
    {
        // TODO pot
    }
}