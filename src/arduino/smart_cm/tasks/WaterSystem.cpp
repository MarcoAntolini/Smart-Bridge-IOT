#include <EnableInterrupt.h>
#include "WaterSystem.h"

volatile bool manualMode = false;
const int buttonPin = PIN_BUTTON;

void interruptButton()
{
    disableInterrupt(buttonPin);
    manualMode = !manualMode;
};

void serialPrint(float distance)
{
    String s = " ";
    int time = millis() / 1000;
    if (distance < maxDistance)
    {
        Serial.println(time + s + distance);
    }
    else
    {
        Serial.println(time + s + maxDistance);
    }
}

void WaterSystem::run()
{
    if (state == State::ALARM_SITUATION && (millis() - lastAlarmTick) < period_alarm)
    {
        alarmTask();
    }
    else
    {
        distance = sonar->detectDistance();
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
    if (Serial.available() > 0)
    {
        servoMotor->open(Serial.read());
    }
    else if (manualMode)
    {
        servoMotor->open(pot->getValue());
    }
    else
    {
        if (distance < distanceAlarm)
        {
            servoMotor->open(180 - map(distance, 0, distanceAlarm, 0, 180));
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
        manualMode = false;
    }
}