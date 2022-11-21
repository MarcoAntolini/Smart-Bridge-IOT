#include "ComponentImpl.h"

ComponentImpl::ComponentImpl(uint8_t pin)
{
    this->pin = pin;
}

void ComponentImpl::setPin(uint8_t pin)
{
    this->pin = pin;
}

uint8_t ComponentImpl::getPin()
{
    return this->pin;
}