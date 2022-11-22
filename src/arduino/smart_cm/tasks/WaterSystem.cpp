#include "Arduino.h"
#include <EnableInterrupt.h>
#include "WaterSystem.h"
#include "..\Config.h"

bool manualMode = false;

void buttonInterrupt()
{
    manualMode = !manualMode;
};

void WaterSystem::run()
{
    if (sonar->detectDistance() < waterLevel_1)
    {
        prevAlarmState = alarmState;
        alarmState = AlarmState::NORMAL_SITUATION;
        checkPrevState();
        normalTask();
    }
    else if (sonar->detectDistance() < waterLevel_2)
    {
        prevAlarmState = alarmState;
        alarmState = AlarmState::PRE_ALARM_SITUATION;
        checkPrevState();
        preAlarmTask();
    }
    else if (sonar->detectDistance() < waterLevel_max)
    {
        prevAlarmState = alarmState;
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
    if ((millis() - lastBlink) >= blinkDelay)
    {
        lastBlink = millis();
        if (ledC->getStatus())
        {
            ledC->switchOff();
        }
        else
        {
            ledC->switchOn();
        }
    }
    monitor->showMessage(alarmState, servoMotor, sonar);
}

void WaterSystem::alarmTask()
{
    if (getPeriod() != period_alarm)
    {
        setPeriod(period_alarm);
    }
    if (lightSystem->getLed()->getStatus())
    {
        lightSystem->getLed()->switchOff();
    }
    lightSystem->setActive(false);
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
    enableInterrupt(button->getPin(), buttonInterrupt, RISING);
    if (manualMode)
    {
        servoMotor->open(pot->getValue());
    }
}

void WaterSystem::checkPrevState()
{
    if (prevAlarmState == AlarmState::ALARM_SITUATION)
    {
        disableInterrupt(button->getPin());
        lightSystem->setActive(true);
        servoMotor->close();
        if (ledC->getStatus())
        {
            ledC->switchOff();
        }
    }
}