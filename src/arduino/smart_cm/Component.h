#ifndef __COMPONENT__
#define __COMPONENT__

class Component
{
public:
    Component(uint8_t pin, uint8_t mode);
    void setPin(uint8_t pin);
    void setMode(uint8_t mode);
    uint8_t getPin();
    uint8_t getMode();

private:
    uint8_t pin;
    uint8_t mode;
};

#endif