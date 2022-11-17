#include "Arduino.h"
#include "LightSensormpl.h"

int LightSensorImpl::getLightIntensity()
{
    return analogRead(getPin());
    /*return map(value,0,1000,0,255);*/
    // mappa un valore da 0 a 1000 -> da 0 a 255
}