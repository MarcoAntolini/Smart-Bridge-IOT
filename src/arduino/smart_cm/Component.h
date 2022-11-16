#ifndef __COMPONENT__
#define __COMPONENT__

#include "IComponent.h"

class Component : public IComponent
{
public:
    void setPin(uint8_t pin);
    void setMode(uint8_t mode);
    uint8_t getPin();
    uint8_t getMode();
};

#endif