#include "Arduino.h"
#include "Led.h"

void Led::switchOn()
{
    digitalWrite(getPin(), HIGH);
}

void Led::switchOff()
{
    digitalWrite(getPin(), LOW);
}