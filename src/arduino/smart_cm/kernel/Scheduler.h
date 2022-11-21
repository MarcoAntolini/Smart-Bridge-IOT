#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "Task.h"

#define MAX_TASKS 20

class Scheduler
{
public:
    virtual void init(int period);
    virtual void schedule();
    virtual void addTask(Task *task);
    virtual void deactivateAll();

private:
    int period;
    int nTask;
    Task *taskList[MAX_TASKS];
};

#endif