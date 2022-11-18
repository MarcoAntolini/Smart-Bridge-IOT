#ifndef __COMPONENT__
#define __COMPONENT__

class Component
{
public:
    virtual void setPin(uint8_t pin) = 0;
    virtual uint8_t getPin() = 0;
};

#endif