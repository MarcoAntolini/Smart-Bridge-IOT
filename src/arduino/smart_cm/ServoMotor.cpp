#include "Arduino.h"
#include "ServoMotor.h"

ServoMotor(int pin)
{
    this->pin = pin;
    pinMode(pin, OUTPUT);
}

/*TODO*/