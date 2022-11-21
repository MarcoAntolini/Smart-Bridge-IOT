#include "..\kernel\Task.h"
#include "..\components\LightSensor.h"
#include "..\components\Light.h"
#include "..\components\Pir.h"

class LightSmartTask : public Task
{
public:
    LightSmartTask(LightSensor *lightSensor, Light *light, Pir *pir) : Task()
    {
        this->lightSensor = lightSensor;
        this->light = light;
        this->pir = pir;
    };
    void run();

private:
    LightSensor *lightSensor;
    Light *light;
    Pir *pir;
    float lightValue;
    bool pirValue;
    bool lightStatus = false;
    int delayTime = 0;
};
