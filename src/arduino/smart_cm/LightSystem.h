#ifndef __LIGHTSYSTEM__
#define __LIGHTSYSTEM__

#include "Led.h"
#include "LightSensor.h"
#include "Pir.h"

class LightSystem
{
public:
    LightSystem(Led *led, LightSensor *lightSensor, Pir *pir);

private:
    Led *ledA;
    LightSensor *lightSensor;
    Pir *pir;
    int lightLevel;
    int offTimer;
    int lightTreshold;
};

#endif