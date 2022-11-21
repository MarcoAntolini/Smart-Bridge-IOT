#ifndef __SONAR__
#define __SONAR__

#include "ComponentImpl.h"

class Sonar
{
public:
    virtual void setIPin(uint8_t pin) = 0;
    virtual void setOPin(uint8_t pin) = 0;
    virtual uint8_t getIPin() = 0;
    virtual uint8_t getOPin() = 0;
    virtual float detectDistance() = 0;
};

#endif