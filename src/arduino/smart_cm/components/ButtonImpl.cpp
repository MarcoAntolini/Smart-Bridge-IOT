#include "ButtonImpl.h"

// ButtonImpl::ButtonImpl(uint8_t pin) : Button(pin)
// {
//     pinMode(pin, INPUT);
// }

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