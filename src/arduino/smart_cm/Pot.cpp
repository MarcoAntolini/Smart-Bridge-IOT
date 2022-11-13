#include "Arduino.h"
#include "Pot.h"

Pot::Pot(int pin)
{
    this->pin = pin;
    pinMode(pin, INPUT);
}

int Pot::getValue()
{
    return this->pin;
}
