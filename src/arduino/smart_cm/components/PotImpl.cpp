#include "Arduino.h"
#include "PotImpl.h"

PotImpl::PotImpl(uint8_t pin) : Pot(pin)
{
    pinMode(pin, INPUT);
}

int PotImpl::getValue()
{
    return map(analogRead(getPin()), 0, 1023, 0, 180);
}