#include "LightSystem.h"
#include "..\Config.h"

void LightSystem::run()
{
    if (lightSensor->getLightIntensity() < lightTreshold)
    {
        if (pir->isDetected())
        {
            if (!ledA->isOn())
            {
                ledA->switchOn();
                onTimer = millis();
            }
        }else if((millis() - onTimer) > lightTimer){
            ledA->switchOff();
        }
    }
    else
    {
        ledA->switchOff();
    }
}

Light *LightSystem::getLed()
{
    return this->ledA;
}