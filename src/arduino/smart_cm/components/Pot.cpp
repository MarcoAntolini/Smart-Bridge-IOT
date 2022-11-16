#include "Arduino.h"
#include "Pot.h"

int Pot::getValue()
{
    return analogRead(getPin());
}
