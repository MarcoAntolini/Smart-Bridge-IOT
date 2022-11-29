#include "Scheduler.h"
#include "..\Config.h"

void Scheduler::init()
{
    this->nTask = 0;
}

void Scheduler::schedule()
{
    for (int i = 0; i < nTask; i++)
    {
        if (taskList[i]->isActive())
        {
            if (taskList[i]->isPeriodic())
            {
                if (taskList[i]->checkPeriod())
                {
                    taskList[i]->run();
                }
            }
            else if (taskList[i]->isLimited())
            {
                if (taskList[i]->checkLimit())
                {
                    taskList[i]->run();
                }
            }
            else
            {
                taskList[i]->run();
            }
        }
    }
}

void Scheduler::addTask(Task *task)
{
    if (nTask < MAX_TASKS - 1)
    {
        taskList[nTask] = task;
        nTask++;
    }
}

void Scheduler::deactivateAll()
{
    for (int i = 0; i < nTask; i++)
    {
        taskList[i]->setActive(false);
    }
}