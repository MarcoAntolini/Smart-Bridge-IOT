#include "Arduino.h"
#include "Pir.h"

bool Pir::isDetected()
{
    if (analogRead(getPin()) == HIGH)
    {
        return true;
    }
    return false;
}