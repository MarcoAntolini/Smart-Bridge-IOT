#include "LedImpl.h"

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

void LedImpl::getStatus()
{
    return this->status;
}