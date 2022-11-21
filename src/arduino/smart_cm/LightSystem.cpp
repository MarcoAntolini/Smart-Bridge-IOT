#include "Arduino.h"
#include "LightSystem.h"

LightSystem::LightSystem(Light *ledA, LightSensor *lightSensor, Pir *pir)
{
    this->ledA = ledA;
    this->lightSensor = lightSensor;
    this->pir = pir;
    this->lightLevel = 0;
}