#ifndef __POTIMPL__
#define __POTIMPL__

#include "Pot.h"

class PotImpl : public Pot
{
public:
    PotImpl(uint8_t pin) : Pot(pin) { pinMode(pin, INPUT); };
    int getValue();
};

#endif
