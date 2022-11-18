#ifndef __SONARIMPL__
#define __SONARIMPL__

#include "Sonar.h"

class SonarImpl : public Sonar
{
public:
    SonarImpl(uint8_t i_pin, uint8_t o_pin);
    void setIPin(uint8_t pin);
    void setOPin(uint8_t pin);
    uint8_t getIPin();
    uint8_t getOPin();
    int detectDistance();

private:
    uint8_t i_pin;
    uint8_t o_pin;
};

#endif