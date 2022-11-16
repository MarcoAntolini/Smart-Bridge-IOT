#include "Arduino.h"
#include "Valve.h"

Valve::Valve()
{
    this->angle = 0;
}

void Valve::close()
{
    this->angle = 0;
}

void Valve::open(int angle)
{
    this->angle = angle;
}