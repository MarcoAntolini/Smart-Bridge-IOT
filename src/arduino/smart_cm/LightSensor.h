#ifndef __LIGHTSENSOR__
#define __LIGHTSENSOR__

class LightSensor
{
public:
    LightSensor(int pin);
    int getLightIntensity();

private:
    int pin;
};

#endif