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
    virtual void run();

private:
    int period;
    int nTask;
    Task *taskList[MAX_TASKS];
};

#endif