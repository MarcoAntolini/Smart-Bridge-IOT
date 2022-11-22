#ifndef __LIGHTSYSTEM__
#define __LIGHTSYSTEM__

#include "..\kernel\Task.h"
#include "..\components\Light.h"
#include "..\components\LightSensor.h"
#include "..\components\Pir.h"

class LightSystem : public Task
{
public:
    LightSystem(Light *ledA, LightSensor *lightSensor, Pir *pir) : Task()
    {
        this->ledA = ledA;
        this->lightSensor = lightSensor;
        this->pir = pir;
        this->onTimer = 0;
    };
    void run();
    Light *getLed();

private:
    Light *ledA;
    LightSensor *lightSensor;
    Pir *pir;
    int onTimer;
};

#endif