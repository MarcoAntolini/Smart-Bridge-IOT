#ifndef __LIGHTSENSOR__
#define __LIGHTSENSOR__

#include "..\ComponentImpl.h"

class LightSensor : public ComponentImpl
{
public:
    using ComponentImpl::ComponentImpl;
    virtual int getLightIntensity() = 0;
};

#endif