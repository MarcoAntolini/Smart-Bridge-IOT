#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "Task.h"

#define MAX_TASKS 20

class Scheduler
{
public:
    Scheduler(int period);
    virtual bool addTask(Task *task);
    virtual void breakTask();

private:
    int period;
    int nTask;
    Task *task1PList[MAX_TASKS];
    Task *task2PList[MAX_TASKS];
};

#endif