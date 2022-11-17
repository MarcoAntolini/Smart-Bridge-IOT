#ifndef __POT__
#define __POT__

#include "Component.h"

class Pot : public Component
{
public:
    using Component::Component;
    virtual int getValue();
};

#endif
