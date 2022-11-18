#ifndef __SONAR__
#define __SONAR__

#include "ComponentImpl.h"

class Sonar : public ComponentImpl
{
public:
    using ComponentImpl::ComponentImpl;
    virtual int detectDistance();
};

#endif