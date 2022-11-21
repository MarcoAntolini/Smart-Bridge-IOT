#ifndef __MONITOR__
#define __MONITOR__

class Monitor
{
public:
    virtual void init() = 0;
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void showMessage() = 0;
    virtual void clear() = 0;
};

#endif