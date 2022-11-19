#include "Scheduler.h"
#include <TimerOne.h>

Scheduler::Scheduler(int period)
{
    nTask = 0;
    this->period = period * 1000;
    Timer1.initialize(this->period);
    Timer1.attachInterrupt(0); // aggiungere metodo chiamato
}