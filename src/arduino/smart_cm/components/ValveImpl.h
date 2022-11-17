#ifndef __VALVEIMPL__
#define __VALVEIMPL__

#include "Valve.h"

class ValveImpl : Valve
{
public:
    ValveImpl();
    void close();
    void open(int angle);

private:
    int angle;
};

#endif