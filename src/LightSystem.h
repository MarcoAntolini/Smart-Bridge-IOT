#ifndef __LIGHTSYSTEM__
#define __LIGHTSYSTEM__

#include "components/Light.h"
#include "components/LightSensor.h"
#include "components/Pir.h"

class LightSystem
{
public:
    LightSystem(Light *led, LightSensor *lightSensor, Pir *pir);

private:
    Light *ledA;
    LightSensor *lightSensor;
    Pir *pir;
    int *lightLevel;
    int *offTimer;
    int *lightTreshold;
};

#endif