#include "Arduino.h"
#include "LedImpl.h"

void LedImpl::switchOn()
{
    digitalWrite(getPin(), HIGH);
}

void LedImpl::switchOff()
{
    digitalWrite(getPin(), LOW);
}