#ifndef __LIGHT__
#define __LIGHT__

#include "Component.h"

class Light : public Component
{
public:
    using Component::Component;
    void switchOn();
    void switchOff();
};

#endif