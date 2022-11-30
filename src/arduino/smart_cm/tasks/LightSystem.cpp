#include "LightSystem.h"
#include "..\Config.h"

void LightSystem::run()
{
    if (lightSensor->getLightIntensity() < lightTreshold)
    {
        if (pir->isDetected() != c)
        {
            Serial.println(pir->isDetected());
        }
        c = pir->isDetected();
        if (pir->isDetected() && !ledA->isOn())
        {
            ledA->switchOn();
            onTimer = millis();
        }
        else if (!pir->isDetected() && (millis() - onTimer) > lightTimer && ledA->isOn())
        {
            ledA->switchOff();
        }
    }
    else
    {
        if (ledA->isOn())
        {
            ledA->switchOff();
        }
    }
}

Light *LightSystem::getLed()
{
    return this->ledA;
}