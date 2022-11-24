#ifndef __LIGHT__
#define __LIGHT__

#include "ComponentImpl.h"

class Light : public ComponentImpl
{
public:
    using ComponentImpl::ComponentImpl;
    virtual void switchOn() = 0;
    virtual void switchOff() = 0;
    virtual bool isOn() = 0;
};

#endif