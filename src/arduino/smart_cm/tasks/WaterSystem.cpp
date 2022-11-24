#include <EnableInterrupt.h>
#include "WaterSystem.h"
#include "..\Config.h"

bool manualMode = false;

void interruptButton()
{
    manualMode = !manualMode;
};

void WaterSystem::run()
{
    if (sonar->detectDistance() < waterLevel_1)
    {
        prevAlarmState = alarmState;
        alarmState = AlarmState::NORMAL_SITUATION;
        Serial.println("Normal situation");
        checkPrevState();
        normalTask();
    }
    else if (sonar->detectDistance() < waterLevel_2)
    {
        prevAlarmState = alarmState;
        alarmState = AlarmState::PRE_ALARM_SITUATION;
        Serial.println("pre situation");
        checkPrevState();
        preAlarmTask();
    }
    else if (sonar->detectDistance() < waterLevel_max)
    {
        prevAlarmState = alarmState;
        Serial.println("alarm situation");
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
    if (!ledB->isOn())
    {
        ledB->switchOn();
    }
    if (ledC->isOn())
    {
        ledC->switchOff();
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
        if (ledC->isOn())
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
    if (lightSystem->getLed()->isOn())
    {
        lightSystem->getLed()->switchOff();
    }
    lightSystem->setActive(false);
    if (ledB->isOn())
    {
        digitalWrite(ledB->getPin(), LOW);
    }
    if (!ledC->isOn())
    {
        digitalWrite(ledC->getPin(), HIGH);
    }
    monitor->showMessage(alarmState, servoMotor, sonar);
    servoMotor->open(180 - map(sonar->detectDistance(), 0, maxDistance, 0, 180));
    enableInterrupt(button->getPin(), interruptButton, RISING);
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
    }
}