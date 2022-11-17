#ifndef __BUTTON__
#define __BUTTON__

#include "Component.h"

class Button : public Component
{
public:
    using Component::Component;
    virtual bool isPressed() = 0;
    virtual void sync() = 0;
    virtual long getLastSyncTime() = 0;
    virtual void updateLastSyncTime(long time) = 0;
};

#endif