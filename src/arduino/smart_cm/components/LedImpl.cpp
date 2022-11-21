#include "LedImpl.h"

// LedImpl::LedImpl(uint8_t pin) : Light(pin)
// {
//     pinMode(pin, OUTPUT);
// }

void LedImpl::switchOn()
{
    digitalWrite(getPin(), HIGH);
    status = true;
}

void LedImpl::switchOff()
{
    digitalWrite(getPin(), LOW);
    status = false;
}