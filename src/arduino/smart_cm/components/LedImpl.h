#ifndef __LEDIMPL__
#define __LEDIMPL__

#include "Light.h"

class LedImpl : public Light
{
public:
    using Light::Light;
    void switchOn();
    void switchOff();
};

#endif