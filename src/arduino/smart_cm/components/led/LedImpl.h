#ifndef __LEDIMPL__
#define __LEDIMPL__

#include "Light.h"

class LedImpl : public Light
{
public:
    LedImpl(uint8_t pin) : Light(pin)
    {
        pinMode(pin, OUTPUT);
        status = false;
    };
    void switchOn();
    void switchOff();
    bool isOn();

private:
    bool status;
};

#endif