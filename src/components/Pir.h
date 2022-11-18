#ifndef __PIR__
#define __PIR__

#include "ComponentImpl.h"

class Pir : public ComponentImpl
{
public:
    using ComponentImpl::ComponentImpl;
    virtual bool isDetected();
};

#endif