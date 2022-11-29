#include <EnableInterrupt.h>
#include "WaterSystem.h"
#include "..\Config.h"

bool manualMode = false;
bool remoteMode = false;
const int buttonPin = PIN_BUTTON;

void interruptButton()
{
    disableInterrupt(buttonPin);
    manualMode = !manualMode;
};

void serialPrint(int distance)
{
    Serial.print(millis());
    Serial.print("  ");
    Serial.println(distance);
}

void WaterSystem::run()
{
    if (state == State::ALARM_SITUATION && (millis() - lastAlarmTick) < period_alarm)
    {
        alarmTask();
    }
    else
    {
        int distance = sonar->detectDistance();
        serialPrint(distance);
        if (distance > distancePreAlarm)
        {
            prevState = state;
            state = State::NORMAL_SITUATION;
            checkPrevState();
            normalTask();
        }
        else if (distance > distanceAlarm && distance <= distancePreAlarm)
        {
            prevState = state;
            state = State::PRE_ALARM_SITUATION;
            checkPrevState();
            preAlarmTask();
        }
        else if (distance <= distanceAlarm)
        {
            prevState = state;
            state = State::ALARM_SITUATION;
            lastAlarmTick = millis();
            alarmTask();
        }
    }
}

void WaterSystem::normalTask()
{
    if (getPeriod() != period_normal)
    {
        setPeriod(period_normal);
        monitor->clear();
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
    if (ledB->isOn())
    {
        ledB->switchOff();
    }
    if (ledC->isOn())
    {
        ledC->switchOff();
    }
    else
    {
        ledC->switchOn();
    }
    monitor->showMessagePreAlarm(sonar);
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
        ledB->switchOff();
    }
    if (!ledC->isOn())
    {
        ledC->switchOn();
    }
    monitor->showMessageAlarm(servoMotor, sonar);
    enableInterrupt(button->getPin(), interruptButton, RISING);
    if (Serial.available() > 0 && Serial.readString() == "remote")
    {
        remoteMode = !remoteMode;
    }
    if (remoteMode)
    {
        if (Serial.available() > 0)
        {
            servoMotor->open(Serial.read());
        }
    }
    else if (manualMode)
    {
        servoMotor->open(pot->getValue());
    }
    else
    {
        if (sonar->detectDistance() < maxDistance)
        {
            servoMotor->open(180 - map(sonar->detectDistance(), 0, maxDistance, 0, 180));
        }
        else
        {
            servoMotor->open(180);
        }
    }
}

void WaterSystem::checkPrevState()
{
    if (prevState == State::ALARM_SITUATION)
    {
        disableInterrupt(button->getPin());
        lightSystem->setActive(true);
        servoMotor->close();
    }
}