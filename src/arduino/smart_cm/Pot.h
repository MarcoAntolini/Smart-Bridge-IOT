#ifndef __POT__
#define __POT__

class Pot
{
public:
    Pot(int pin);
    int getValue();
    
private:
    int pin;
};

#endif
