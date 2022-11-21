#include "LightSmartTask.h"
#include "..\Config.h"

void LightSmartTask::run()
{
    while (true)
    {
        lightValue = lightSensor->getLightIntensity();
        pirValue = pir->isDetected();
        if (pirValue)
        {
            light->switchOn();
            lightStatus = true;
            delayTime = millis();
        }
        else
        {
            if (lightStatus)
            {
                if (millis() - delayTime > lightTimer)
                {
                    light->switchOff();
                    lightStatus = true;
                }
            }
        }
        if (lightValue < lightTreshold)
        {
            light->switchOn();
            lightStatus = true;
        }
        else
        {
            if (lightStatus)
            {
                light->switchOff();
                lightStatus = false;
            }
        }
    }
}