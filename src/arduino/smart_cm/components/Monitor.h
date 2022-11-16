#ifndef __MONITOR__
#define __MONITOR__

#include "../../../lib/LiquidCrystal_I2C/LiquidCrystal_I2C.h"

class Monitor
{
public:
    void showMessage();
    void clear();

private:
    LiquidCrystal_I2C lcd;
};

#endif