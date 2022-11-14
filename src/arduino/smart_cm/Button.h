#ifndef __BUTTON__
#define __BUTTON__

class Button
{
public:
    Button(int pin);
    bool isPressed();
    void sync();
    long getLastSyncTime();
    void updateLastSyncTime(long time);

private:
    int pin;
    bool pressed;
    long lastSyncTime;
};

#endif