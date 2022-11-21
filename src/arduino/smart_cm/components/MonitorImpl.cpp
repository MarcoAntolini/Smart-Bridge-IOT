#include "Arduino.h"
#include "MonitorImpl.h"

// TODO togliere:
#include "../AlarmState.h"
#include "ServoMotorImpl.h"
#include "SonarImpl.h"

String alarm = "Alarm Situation";
String preAlarm = "Pre Alarm Situation";
String water = "Current water level: ";
String valves = "Current valves opening degrees: ";

MonitorImpl::MonitorImpl(uint8_t addr, uint8_t cols, uint8_t rows)
{
    this->lcd = new LiquidCrystal_I2C(addr, cols, rows);
}

void MonitorImpl::init()
{
    lcd->init();
    lcd->backlight();
}

void MonitorImpl::turnOn()
{
    lcd->display();
}

void MonitorImpl::turnOff()
{
    lcd->noDisplay();
}

void MonitorImpl::showMessage()
{
    lcd->clear();
    lcd->setCursor(1, 1);

    // TODO togliere:
    AlarmState alarmState = AlarmState::NORMAL_SITUATION;
    ServoMotor *servoMotor = new ServoMotorImpl(0);
    Sonar *sonar = new SonarImpl(0, 0);

    if (alarmState == AlarmState::PRE_ALARM_SITUATION)
    {
        lcd->print(preAlarm);
        lcd->setCursor(2, 1);
        lcd->print(water + sonar->detectDistance());
    }
    else if (alarmState == AlarmState::ALARM_SITUATION)
    {
        lcd->print(alarm);
        lcd->setCursor(2, 1);
        lcd->print(water + sonar->detectDistance());
        lcd->setCursor(3, 1);
        lcd->print(valves + servoMotor->getAngle());
    }
}