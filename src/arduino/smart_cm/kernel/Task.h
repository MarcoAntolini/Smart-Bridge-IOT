#ifndef __TASK__
#define __TASK__

class Task
{
public:
    Task()
    {
        this->active = false;
    }

    virtual void init()
    {
        this->active = true;
        this->period = false;
    }

    virtual void init(int period)
    {
        this->active = true;
        this->periodic = true;
        this->period = period;
        this->timeElapsed = 0;
    }

    void setPeriod(int period)
    {
        this->period = period;
    }

    int getPeriod()
    {
        return this->period;
    }

    void setActive(bool status)
    {
        this->active = status;
        this->timeElapsed = 0;
    }

    bool isActive()
    {
        return this->active;
    }

    bool isPeriodic()
    {
        return this->periodic;
    }

    bool checkPeriod(int time)
    {
        timeElapsed += time;
        if (timeElapsed >= period)
        {
            timeElapsed = 0;
            active = false;
            return false;
        }
        else
        {
            return true;
        }
    }

    virtual void run() = 0;

private:
    int period;
    int timeElapsed;
    bool active;
    bool periodic;
};

#endif