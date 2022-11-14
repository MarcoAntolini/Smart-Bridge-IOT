#include "Arduino.h"
#include "Sonar.h"

Sonar::Sonar(int pin)
{
    this->pin = pin;
    pinMode(pin, INPUT);
}

void Sonar::detectDistance()
{
    return analogRead(pin);
}