#include "PirImpl.h"

// PirImpl::PirImpl(uint8_t pin) : Pir(pin)
// {
//     pinMode(pin, INPUT);
// }

bool PirImpl::isDetected()
{
    return analogRead(getPin()) == HIGH ? true : false;
}