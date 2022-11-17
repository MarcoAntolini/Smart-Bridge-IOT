#include "Arduino.h"
#include "ButtonImpl.h"

bool ButtonImpl::isPressed()
{
    return pressed;
}

void ButtonImpl::sync()
{
    pressed = digitalRead(getPin()) == HIGH;
    updateLastSyncTime(millis());
}

long ButtonImpl::getLastSyncTime()
{
    return lastSyncTime;
}

void ButtonImpl::updateLastSyncTime(long time)
{
    lastSyncTime = time;
}