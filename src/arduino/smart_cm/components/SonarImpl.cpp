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

float SonarImpl::detectDistance()
{
    digitalWrite(o_pin, LOW);
    delayMicroseconds(3);
    digitalWrite(o_pin, HIGH);
    delayMicroseconds(5);
    digitalWrite(o_pin, LOW);
    duration = pulseIn(i_pin, HIGH) / 1000000;
    distance = duration * 343 / 2;
    return analogRead(this->i_pin);
}