#include "PirImpl.h"

bool PirImpl::isDetected()
{
    return analogRead(getPin()) == HIGH ? true : false;
}