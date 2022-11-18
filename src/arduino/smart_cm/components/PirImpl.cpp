#include "Arduino.h"
#include "PirImpl.h"

bool PirImpl::isDetected()
{
    if (analogRead(getPin()) == HIGH)
    {
        lastSyncTime = millis();
        return true;
    }
    return false;
}

long PirImpl::getLastSyncTime()
{
    return this->lastSyncTime;
}