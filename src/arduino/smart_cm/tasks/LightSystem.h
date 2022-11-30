#ifndef __LIGHTSYSTEM__
#define __LIGHTSYSTEM__

#include "..\kernel\Task.h"
#include "..\components\led\LedImpl.h"
#include "..\components\lightSensor\LightSensorImpl.h"
#include "..\components\pir\PirImpl.h"

class LightSystem : public Task
{
public:
    LightSystem(Light *ledA, LightSensor *lightSensor, Pir *pir) : Task()
    {
        this->ledA = ledA;
        this->lightSensor = lightSensor;
        this->pir = pir;
        this->onTimer = 0;
        c = false;
    };
    void run();
    Light *getLed();

private:
    Light *ledA;
    LightSensor *lightSensor;
    Pir *pir;
    int onTimer;
    bool c;
};

#endif