#include "LightSystem.h"
#include "..\Config.h"

void LightSystem::run()
{
    if (pir->isDetected())
    {
        if (lightSensor->getLightIntensity() < lightTreshold)
        {
            if (!ledA->isOn())
            {
                ledA->switchOn();
                onTimer = millis();
            }
        }
    }
    else if ((millis() - onTimer) > lightTimer || lightSensor->getLightIntensity() > lightTreshold)
    {
        ledA->switchOff();
    }
}

Light *LightSystem::getLed()
{
    return this->ledA;
}