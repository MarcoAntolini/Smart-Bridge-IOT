#include "Scheduler.h"
#include <TimerOne.h>
#include "..\Config.h"

void interruptTimer()
{
    timerFlag = true;
}

void Scheduler::init(int period)
{
    this->nTask = 0;
    this->period = period * 1000;
    timerFlag = false;
    Timer1.initialize(this->period);
    Timer1.attachInterrupt(interruptTimer);
}

void Scheduler::schedule()
{
    while (!timerFlag)
    {
    }
    timerFlag = false;
    for (int i = 0; i < nTask; i++)
    {
        if (taskList[i]->isActive())
        {
            if (taskList[i]->isPeriodic())
            {
                if (taskList[i]->checkPeriod(period))
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