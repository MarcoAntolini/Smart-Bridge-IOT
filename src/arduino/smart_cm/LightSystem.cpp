#include "Arduino.h"
#include "LightSystem.h"

LightSystem(Led ledA, LightSensor lightSensor, Pir pir)
{
    this->ledA = ledA;
    this->lightSensor = lightSensor;
    this->pir = pir;
    this->lightLevel = 0;
    this->offTimer = 0;
    this->lightTreshold = 0;
}