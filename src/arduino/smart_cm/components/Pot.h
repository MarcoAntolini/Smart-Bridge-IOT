#ifndef __POT__
#define __POT__

#include "ComponentImpl.h"

class Pot : public ComponentImpl
{
public:
    using ComponentImpl::ComponentImpl;
    virtual int getValue();
    virtual long getLastSyncTime();
};

#endif
