#ifndef __LIGHT__
#define __LIGHT__

#include "ComponentImpl.h"

class Light : public ComponentImpl
{
public:
    using ComponentImpl::ComponentImpl;
    void switchOn();
    void switchOff();
};

#endif