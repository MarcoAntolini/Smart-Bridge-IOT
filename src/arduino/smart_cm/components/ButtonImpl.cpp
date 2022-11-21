#include "ButtonImpl.h"

bool ButtonImpl::isPressed()
{
    return digitalRead(getPin()) == HIGH;
}