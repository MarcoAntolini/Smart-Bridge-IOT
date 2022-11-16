#include "Arduino.h"
#include "Component.h"

Component::Component(uint8_t pin, uint8_t mode)
{
    this->pin = pin;
    this->mode = mode;
}

void Component::setPin(uint8_t pin)
{
    this->pin = pin;
}

void Component::setMode(uint8_t mode)
{
    this->mode = mode;
}

uint8_t Component::getPin()
{
    return this->pin;
}

uint8_t Component::getMode()
{
    return this->mode;
}