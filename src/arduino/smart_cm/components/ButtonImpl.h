#ifndef __BUTTONIMPL__
#define __BUTTONIMPL__

#include "Button.h"

class ButtonImpl : public Button
{
public:
    ButtonImpl(uint8_t pin) : Button(pin)
    {
        pinMode(pin, INPUT);
        lastDebounceTime = millis();
    };
    bool isPressed();

private:
    unsigned long lastDebounceTime;
};

#endif