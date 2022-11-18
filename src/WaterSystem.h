#ifndef __WATERSYSTEM__
#define __WATERSYSTEM__

#include "AlarmState.h"

class WaterSystem
{
public:
    // costruttore
    void setAlarmState(AlarmState alarmState);
    AlarmState getAlarmState();

private:
    AlarmState alarmState;
};

#endif