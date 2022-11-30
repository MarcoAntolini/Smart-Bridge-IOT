#include <EnableInterrupt.h>
#include "WaterSystem.h"

volatile bool manualMode = false;
const uint8_t buttonPin = PIN_BUTTON;

void interruptButton()
{
    disableInterrupt(buttonPin);
    manualMode = !manualMode;
};

void WaterSystem::run()
{
    if (state == State::ALARM_SITUATION && (millis() - lastAlarmTick) < period_alarm)
    {
        alarmTask();
    }
    else
    {
        distance = sonar->detectDistance();
        if (distance > distancePreAlarm)
        {
            prevState = state;
            state = State::NORMAL_SITUATION;
            alarmState = normal;
            checkPrevState();
            normalTask();
        }
        else if (distance > distanceAlarm && distance <= distancePreAlarm)
        {
            prevState = state;
            state = State::PRE_ALARM_SITUATION;
            alarmState = preAlarm;
            checkPrevState();
            preAlarmTask();
        }
        else if (distance <= distanceAlarm)
        {
            prevState = state;
            state = State::ALARM_SITUATION;
            alarmState = alarm;
            lastAlarmTick = millis();
            alarmTask();
        }
    }
    serialPrint();
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
    if (manualMode)
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

void WaterSystem::serialPrint()
{
    timer = millis() / 1000;
    lightState = lightSystem->getLed()->toString();
    if (distance < maxDistance)
    {
        waterLevel = maxDistance - distance;
    }
    else
    {
        waterLevel = 0;
    }
    Serial.println(timer + sep + waterLevel + sep + lightState + sep + alarmState);
}