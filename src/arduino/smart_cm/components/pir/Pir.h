#ifndef __PIR__
#define __PIR__

#include "..\ComponentImpl.h"

class Pir : public ComponentImpl
{
public:
    Pir(uint8_t pin) : ComponentImpl(pin) { delay(calibrationTime); };
    virtual bool isDetected() = 0;
};

#endif