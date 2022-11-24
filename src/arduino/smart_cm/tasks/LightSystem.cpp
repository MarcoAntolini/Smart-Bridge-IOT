#include "LightSystem.h"
#include "..\Config.h"

void LightSystem::run()
{
    Serial.println("LightSystem::run()");
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
    if ((millis() - onTimer) > lightTimer && (!pir->isDetected() || lightSensor->getLightIntensity() > lightTreshold))
    {
        ledA->switchOff();
    }
}

Light *LightSystem::getLed()
{
    return this->ledA;
}