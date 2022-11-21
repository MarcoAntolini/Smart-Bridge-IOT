#include "PotImpl.h"

int PotImpl::getValue()
{
    return map(analogRead(getPin()), 0, 1023, 0, 180);
}