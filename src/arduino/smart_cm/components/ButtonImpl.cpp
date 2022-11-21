#include "ButtonImpl.h"

// ButtonImpl::ButtonImpl(uint8_t pin) : Button(pin)
// {
//     pinMode(pin, INPUT);
// }

bool ButtonImpl::isPressed()
{
    return digitalRead(getPin()) == HIGH;
}