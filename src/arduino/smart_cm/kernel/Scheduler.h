#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "Task.h"

#define MAX_TASKS 20

class Scheduler
{
public:
    Scheduler(int period);
    virtual void interruptTimer();
    virtual void schedule();
    virtual bool addTask(Task *task);
    virtual void deactivateAll();
    virtual void breakTask();

private:
    int period;
    int nTask;
    Task *taskList[MAX_TASKS];
    volatile bool timerFlag;
};

#endif