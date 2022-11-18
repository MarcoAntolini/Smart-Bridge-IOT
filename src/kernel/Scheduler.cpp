#include "Schedule.h"
#include <TimerOne.h>

Scheduler::scheduler(int period)
{
    nTask = 0;
    this->period = period * 1000;
    Timer1.initialize(this->period);
    Timer1.attachInterrupt();
}