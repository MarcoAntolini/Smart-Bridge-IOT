#include "Arduino.h"
#include "LightSensor.h"

int LightSensor::getLightIntensity()
{
    return analogRead(getPin());
    /*return map(value,0,1000,0,255);*/
}