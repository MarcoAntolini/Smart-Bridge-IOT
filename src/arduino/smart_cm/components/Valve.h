#ifndef __VALVE__
#define __VALVE__

class Valve
{
public:
    Valve();
    void close();
    void open(int angle);

private:
    int angle;
};

#endif