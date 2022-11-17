#ifndef __LIGHTSENSOR__
#define __LIGHTSENSOR__

#include "Component.h"

class LightSensor : public Component
{
public:
    using Component::Component;
    int getLightIntensity();
};

#endif