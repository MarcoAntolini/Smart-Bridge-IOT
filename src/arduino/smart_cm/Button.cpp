#include "Arduino.h"
#include "Button.h"

Button::Button(int pin)
{
    this->pin = pin;
    pinMode(pin, INPUT);
    sync();
}

bool Button::isPressed()
{
    return pressed;
}

void Button::sync()
{
    pressed = digitalRead(pin) == HIGH;
    updateLastSyncTime(millis());
}

long Button::getLastSyncTime()
{
    return lastSyncTime;
}

void Button::updateLastSyncTime(long time)
{
    lastSyncTime = time;
}