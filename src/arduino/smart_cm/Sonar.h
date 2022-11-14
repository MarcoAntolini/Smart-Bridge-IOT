#ifndef __SONAR__
#define __SONAR__

class Sonar
{
public:
    LightSystem(int pin);
    void detectDistance();
    
private:
    int pin;
};

#endif