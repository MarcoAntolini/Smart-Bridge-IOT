#ifndef __LIGHTSENSORIMPL__
#define __LIGHTSENSORIMPL__

#include "LightSensor.h"

class LightSensorImpl : public LightSensor
{
public:
    using LightSensor::LightSensor;
    int getLightIntensity();
};

#endif