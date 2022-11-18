#ifndef __LEDIMPL__
#define __LEDIMPL__

#include "Light.h"

class LedImpl : public Light
{
public:
    LedImpl(uint8_t pin) : Light(pin){};
    void switchOn();
    void switchOff();
};

#endif