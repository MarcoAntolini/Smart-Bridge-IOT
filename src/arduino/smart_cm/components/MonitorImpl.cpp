#include "MonitorImpl.h"
#include "..\Config.h"

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

void MonitorImpl::showMessageAlarm(ServoMotor *servoMotor, Sonar *sonar)
{
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("Alarm State");
    lcd->setCursor(0, 1);
    lcd->print("WL: ");
    lcd->setCursor(3, 1);
    lcd->print(sonar->detectDistance());
    lcd->setCursor(10, 1);
    lcd->print("°: ");
    lcd->setCursor(13, 1);
    lcd->print(servoMotor->getAngle());
}

void MonitorImpl::showMessagePreAlarm(Sonar *sonar)
{
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("Pre Alarm State");
    lcd->setCursor(0, 1);
    lcd->print(water + sonar->detectDistance());
}