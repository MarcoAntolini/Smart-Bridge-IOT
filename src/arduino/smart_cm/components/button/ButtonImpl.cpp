#include "ButtonImpl.h"

bool ButtonImpl::isPressed()
{
    if (digitalRead(getPin()) == HIGH)
    {
        if ((millis() - lastDebounceTime) > debounceDelay)
        {
            lastDebounceTime = millis();
            return true;
        }
    }
    return false;
}