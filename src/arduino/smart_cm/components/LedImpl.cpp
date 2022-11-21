#include "LedImpl.h"

// LedImpl::LedImpl(uint8_t pin) : Light(pin)
// {
//     pinMode(pin, OUTPUT);
// }

void LedImpl::switchOn()
{
    digitalWrite(getPin(), HIGH);
}

void LedImpl::switchOff()
{
    digitalWrite(getPin(), LOW);
}