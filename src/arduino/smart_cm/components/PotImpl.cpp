#include "Arduino.h"
#include "PotImpl.h"

int PotImpl::getValue()
{
    return analogRead(getPin());
}
