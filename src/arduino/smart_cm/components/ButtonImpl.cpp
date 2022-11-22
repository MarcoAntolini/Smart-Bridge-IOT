#include "ButtonImpl.h"
#include "..\Config.h"

bool ButtonImpl::isPressed()
{
    if (digitalRead(getPin()) == HIGH)
    {
        if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY)
        {
            lastDebounceTime = millis();
            return true;
        }
    }
    return false;
}

bool ButtonImpl::isEnabled()
{
    return this->enabled;
}

void ButtonImpl::setEnabled(bool status)
{
    this->enabled = status;
}