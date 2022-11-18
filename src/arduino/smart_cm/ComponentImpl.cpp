#include "Arduino.h"
#include "ComponentImpl.h"

ComponentImpl::ComponentImpl(uint8_t pin, uint8_t mode)
{
    this->pin = pin;
    this->mode = mode;
}

void ComponentImpl::setPin(uint8_t pin)
{
    this->pin = pin;
}

void ComponentImpl::setMode(uint8_t mode)
{
    this->mode = mode;
}

uint8_t ComponentImpl::getPin()
{
    return this->pin;
}

uint8_t ComponentImpl::getMode()
{
    return this->mode;
}