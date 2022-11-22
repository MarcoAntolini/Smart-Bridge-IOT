#ifndef __BUTTON__
#define __BUTTON__

#include "ComponentImpl.h"

class Button : public ComponentImpl
{
public:
    using ComponentImpl::ComponentImpl;
    virtual bool isPressed() = 0;
    virtual bool isEnabled() = 0;
    virtual void setEnabled(bool status) = 0;
};

#endif