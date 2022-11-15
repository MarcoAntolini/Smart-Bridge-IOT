#ifndef __SONAR__
#define __SONAR__

class Sonar
{
public:
    Sonar(int pin);
    int detectDistance();

private:
    int pin;
};

#endif