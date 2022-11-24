#include "LightSystem.h"
#include "..\Config.h"

void LightSystem::run()
{
    Serial.println("LightSystem::run()");
    if (pir->isDetected())
    {
        if(0 < lightTreshold)                    //if (lightSensor->getLightIntensity() < lightTreshold)
        {
            if (!ledA->isOn())
            {
                ledA->switchOn();
                onTimer = millis();
            }
        }
    }else if ((millis() - onTimer) > lightTimer || 0 > lightTreshold)
    {
         ledA->switchOff();
    }
}

Light *LightSystem::getLed()
{
    return this->ledA;
}