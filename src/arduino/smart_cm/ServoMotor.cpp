#include "Arduino.h"
#include "ServoMotor.h"

ServoMotor::ServoMotor(int pin)
{
    this->pin = pin;
    pinMode(pin, OUTPUT);
}

/*TODO*/