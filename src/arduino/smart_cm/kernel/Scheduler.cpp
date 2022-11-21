#include "Scheduler.h"
#include <TimerOne.h>

volatile bool timerFlag;

static void interruptTimer()
{
    timerFlag = true;
}

Scheduler::Scheduler(int period)
{
    this->nTask = 0;
    this->period = period * 1000;
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
        Timer1.restart();
        if (taskList[i]->isActive() && taskList[i]->update(period))
        {
            taskList[i]->run();
        }
    }
}

bool Scheduler::addTask(Task *task)
{
    if (nTask < MAX_TASKS - 1)
    {
        taskList[nTask] = task;
        nTask++;
        return true;
    }
    return false;
}

void Scheduler::deactivateAll()
{
    for (int i = 0; i < nTask; i++)
    {
        taskList[i]->setActive(false);
    }
}

void Scheduler::breakTask()
{
    Timer1.stop();
}