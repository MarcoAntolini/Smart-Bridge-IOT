#include "Arduino.h"
#include "SonarImpl.h"

SonarImpl::SonarImpl(uint8_t i_pin, uint8_t o_pin)
{
    this->i_pin = i_pin;
    this->o_pin = o_pin;
    pinMode(i_pin, INPUT);
    pinMode(o_pin, OUTPUT);
}

void SonarImpl::setIPin(uint8_t pin)
{
    this->i_pin = pin;
}

void SonarImpl::setOPin(uint8_t pin)
{
    this->o_pin = pin;
}

uint8_t SonarImpl::getIPin()
{
    return this->i_pin;
}

uint8_t SonarImpl::getOPin()
{
    return this->o_pin;
}

int SonarImpl::detectDistance()
{
    return analogRead(this->i_pin);
}