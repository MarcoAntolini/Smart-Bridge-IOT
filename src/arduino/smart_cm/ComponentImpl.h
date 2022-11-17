#ifndef __COMPONENTIMPL__
#define __COMPONENTIMPL__

#include "Component.h"

class ComponentImpl : public Component
{
public:
    ComponentImpl(uint8_t pin, uint8_t mode);
    void setPin(uint8_t pin);
    void setMode(uint8_t mode);
    uint8_t getPin();
    uint8_t getMode();

private:
    uint8_t pin;
    uint8_t mode;
};

#endif