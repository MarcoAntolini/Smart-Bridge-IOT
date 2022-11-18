#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "Task.h"

#define MAX_TASKS 20

class Scheduler
{
private:
    int period;
    int nTasks;
    Task* task1PList[MAX_TASKS];
    Task* task2PList[MAX_TASKS];

public:
    Scheduler(int period);

    virtual bool addTask(Task *task);
    virtual void breakTask();
};

#endif