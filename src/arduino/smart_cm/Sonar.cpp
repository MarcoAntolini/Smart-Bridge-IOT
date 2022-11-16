#include "Arduino.h"
#include "Sonar.h"

int Sonar::detectDistance()
{
    return analogRead(getPin());
}