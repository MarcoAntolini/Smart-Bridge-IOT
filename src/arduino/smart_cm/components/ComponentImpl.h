#ifndef __COMPONENTIMPL__
#define __COMPONENTIMPL__

#include "Component.h"

class ComponentImpl : public Component
{
public:
    ComponentImpl(uint8_t pin);
    void setPin(uint8_t pin);
    uint8_t getPin();

private:
    uint8_t pin;
};

#endif