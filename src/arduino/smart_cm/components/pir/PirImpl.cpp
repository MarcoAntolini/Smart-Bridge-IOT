#include "PirImpl.h"

bool PirImpl::isDetected()
{
    return digitalRead(getPin()) == HIGH ? true : false;
}