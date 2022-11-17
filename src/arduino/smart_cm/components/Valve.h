#ifndef __VALVE__
#define __VALVE__

class Valve
{
public:
    virtual void close();
    virtual void open(int angle);
};

#endif