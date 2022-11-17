#include "Arduino.h"
#include "SonarImpl.h"

int SonarImpl::detectDistance()
{
    return analogRead(getPin());
}