#ifndef __BUTTONIMPL__
#define __BUTTONIMPL__

#include "Button.h"

class ButtonImpl : public Button
{
public:
    using Button::Button;
    bool isPressed();
    void sync();
    long getLastSyncTime();
    void updateLastSyncTime(long time);

private:
    bool pressed;
    long lastSyncTime;
};

#endif