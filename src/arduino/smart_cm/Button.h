#ifndef __BUTTON__
#define __BUTTON__

#include "Component.h"

class Button : public Component
{
public:
    using Component::Component;
    bool isPressed();
    void sync();
    long getLastSyncTime();
    void updateLastSyncTime(long time);

private:
    bool pressed;
    long lastSyncTime;
};

#endif