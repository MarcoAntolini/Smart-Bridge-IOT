#include "Arduino.h"
#include "PirImpl.h"

bool PirImpl::isDetected()
{
    if (analogRead(getPin()) == HIGH)
    {
        return true;
    }
    return false;
}