#include "Arduino.h"
#include "Button.h"

bool Button::isPressed()
{
    return pressed;
}

void Button::sync()
{
    pressed = digitalRead(getPin()) == HIGH;
    updateLastSyncTime(millis());
}

long Button::getLastSyncTime()
{
    return lastSyncTime;
}

void Button::updateLastSyncTime(long time)
{
    lastSyncTime = time;
}