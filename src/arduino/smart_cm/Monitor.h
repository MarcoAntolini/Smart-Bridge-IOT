#ifndef __MONITOR__
#define __MONITOR__

#include <string>
using namespace std;

class Monitor
{
public:
    Monitor(int pin);
    void showMessage();

private:
    int pin;
};

#endif