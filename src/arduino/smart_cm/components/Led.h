#ifndef __LED__
#define __LED__

#include "Component.h"

class Led : public Component
{
public:
    using Component::Component;
    void switchOn();
    void switchOff();
};

#endif