#include "Arduino.h"
#include "LightSystem.h"
#include "..\Config.h"

void LightSystem::run()
{
    if (pir->isDetected())
    {
        if (lightSensor->getLightIntensity() < lightTreshold)
        {
            if (!ledA->getStatus())
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