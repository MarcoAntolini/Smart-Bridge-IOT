#include "Arduino.h"
#include "Pir.h"

Pir::Pir(int pin)
{
    this->pin = pin;
    pinMode(pin, OUTPUT);
}

bool isSomething()
{
  return this->pin;
}
