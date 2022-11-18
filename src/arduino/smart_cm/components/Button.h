#ifndef __BUTTON__
#define __BUTTON__

#include "ComponentImpl.h"

class Button : public ComponentImpl
{
public:
    using ComponentImpl::ComponentImpl;
    virtual bool isPressed() = 0;
    virtual void sync() = 0;
    virtual long getLastSyncTime() = 0;
    virtual void updateLastSyncTime(long time) = 0;
};

#endif