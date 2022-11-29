#include "LightSensorImpl.h"

int LightSensorImpl::getLightIntensity()
{
    return analogRead(getPin());
}