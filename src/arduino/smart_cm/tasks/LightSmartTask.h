#include "..\kernel\Task.h"
#include "..\components\LightSensor"
#include "..\components\Light"
#include "..\components\Pir"

class LightSmartTask : public Task
{
public:
    LightSmartTask(int period, LightSensor *lightSensor, Light *light, Pir *pir) : Task(period) { this->lightSensor = lightSensor; this->light = light; this->pir = pir; };
    void run();

private:
    LightSensor *lightSensor;
    Light *light;
    Pir *pir;
    float lightValue;
    bool pirValue;
    bool lightStatus = FALSE;
    int delayTime = 0;
};
