#include "Scheduler.h"
#include <TimerOne.h>

Scheduler::Scheduler(int period)
{
    nTask = 0;
    this->period = period * 1000;
    Timer1.initialize(this->period);
    Timer1.attachInterrupt(Scheduler::run);
    int i = 0;
}

bool Scheduler::addTask(Task *task)
{
    if (nTask < MAX_TASKS)
    {
        taskList[nTask++] = task;
        return true;
    }
    return false;
}

void Scheduler::breakTask()
{
    Timer1.stop();
}


void Scheduler::run()
{
    for (; i < nTask; i++)
    {
        Timer1.restart();
        if (taskList[i]->isActive())
        {
            taskList[i]->run();
        }
    }
}