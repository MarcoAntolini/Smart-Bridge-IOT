#include "LightSensorImpl.h"

int LightSensorImpl::getLightIntensity()
{
    return map(analogRead(getPin()), 0, 1023, 0, 100);
}