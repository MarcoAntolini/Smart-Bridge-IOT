#ifndef __CLOCK__
#define __CLOCK__

class Clock
{
public:
    Clock();
    void setupFreq();
    void setupPeriod();
    void waitNextTick();
};

#endif