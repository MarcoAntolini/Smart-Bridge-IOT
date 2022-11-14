#ifndef __PIR__
#define __PIR__

class Pir
{
public:
    Pir(int pin);
    bool isDetected();

private:
    int pin;
};

#endif