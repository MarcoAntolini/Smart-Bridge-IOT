#include "Arduino.h"
#include "LightSensor.h"

LightSensor::LightSensor(int pin)
{
    this->pin = pin;
    pinMode(pin, INPUT);
}

int LightSensor::getLightIntensity()
{
    return analogRead(pin);
}