#include "Arduino.h"
#include "MonitorImpl.h"

#include "AlarmState.h"
#include "Valve.h"

#include <iostream>
#include <string>
using namespace std;

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
    Valve *valve = new Valve();

    if (alarmState == AlarmState::PRE_ALARM_SITUATION)
    {
        lcd->print(preAlarm);
        lcd->setCursor(2, 1);
        lcd->print(water +);
    }
    else if (alarmState == AlarmState::ALARM_SITUATION)
    {
        lcd->print(alarm);
        lcd->setCursor(2, 1);
        lcd->print(water +);
        lcd->setCursor(3, 1);
        lcd->print(valves + to_string(valve->getAngle));
    }
}