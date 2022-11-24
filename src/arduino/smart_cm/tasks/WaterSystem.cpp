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
    Serial.println("WaterSystem::run()");
    Serial.println(sonar->detectDistance());
    if (sonar->detectDistance() > distancePreAlarm)
    {
        prevAlarmState = alarmState;
        alarmState = AlarmState::NORMAL_SITUATION;
        Serial.println("Normal situation");
        checkPrevState();
        normalTask();
    }
    else if (sonar->detectDistance() > distanceAlarm && sonar->detectDistance() <= distancePreAlarm)
    {
        prevAlarmState = alarmState;
        alarmState = AlarmState::PRE_ALARM_SITUATION;
        Serial.println("pre situation");
        checkPrevState();
        preAlarmTask();
    }
    else if (sonar->detectDistance() <= distanceAlarm)
    {
        prevAlarmState = alarmState;
        Serial.println("alarm situation");
        alarmState = AlarmState::ALARM_SITUATION;
        alarmTask();
    }
    delay(1000);
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
    Serial.println("preAlarmTask");
    if (getPeriod() != period_preAlarm)
    {
        setPeriod(period_preAlarm);
    }
    Serial.println("qui?");
    //se sono entrato nel task in stato di preallarme sono già passati 2 secondi dall'ultima volta
    if (ledC->isOn())
    {
        ledC->switchOff();
    }
    else
    {
        ledC->switchOn();
    }
    Serial.println("o qui?");
    monitor->showMessagePreAlarm(sonar);
    Serial.println("no qui?");
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
    monitor->showMessageAlarm(servoMotor, sonar);
    servoMotor->open(180 - map(sonar->detectDistance(), 0, maxDistance, 0, 180));
    enableInterrupt(button->getPin(), interruptButton, RISING);
    if (manualMode)
    {
        servoMotor->open(pot->getValue());
    }
}

void WaterSystem::checkPrevState()
{
    Serial.println("checkPrevState");
    if (prevAlarmState == AlarmState::ALARM_SITUATION)
    {
        disableInterrupt(button->getPin());
        lightSystem->setActive(true);
        servoMotor->close();
    }
}