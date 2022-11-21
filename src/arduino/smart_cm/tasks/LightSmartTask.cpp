#include "LightSmartTask.h"
#include "..\Config.h"

void LightSmartTask::run()
{
    while (TRUE)
    {
        lightValue = lightSensor->readLight();
        pirValue = pir->readPir();
        if(pirValue == TRUE)
        {
            light->switchOn();
            lightStatus = TRUE;
            delayTime = millis();
        }else{
            if(lightStatus == TRUE)
            {
                if(millis() - delayTime > lightTimer)
                {
                    light->switchOff();
                    lightStatus = FALSE;
                }
            }
        }
        if(lightValue < lightTreshold)
        {
            light->switchOn();
            lightStatus = TRUE;
        }else{
            if(lightStatus == TRUE)
            {
                light->switchOff();
                lightStatus = FALSE;
            }
        }
        
    }
}