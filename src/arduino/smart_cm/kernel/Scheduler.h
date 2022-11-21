#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "Task.h"
#include "..\Config.h"

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