#ifndef __LIGHTSYSTEM__
#define __LIGHTSYSTEM__

class LightSystem
{
public:
    LightSystem(Led ledA, LightSensor lightSensor, Pir pir);
    
private:
    Led ledA;
    LightSensor lightSensor;
    Pir pir;
    int lightLevel;
    int offTimer;
    int lightTreshold;
};

#endif