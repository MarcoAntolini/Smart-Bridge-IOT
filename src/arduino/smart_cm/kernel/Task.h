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
        this->periodic = false;
        this->limited = false;
    }

    virtual void initPeriodic(int period)
    {
        this->active = true;
        this->periodic = true;
        this->limited = false;
        this->period = period;
        this->timeElapsed = 0;
    }

    virtual void initLimited(int endTime)
    {
        this->active = true;
        this->periodic = false;
        this->limited = true;
        this->endTime = endTime;
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
        active = status;
        timeElapsed = 0;
    }

    bool isActive()
    {
        return this->active;
    }

    bool isPeriodic()
    {
        return this->periodic;
    }

    bool isLimited()
    {
        return this->limited;
    }

    bool checkPeriod(int time)
    {
        timeElapsed = time;
        if (timeElapsed >= period)
        {
            return true;
        }
        return false;
    }

    bool checkLimit(int time)
    {
        timeElapsed += time;
        if (timeElapsed >= endTime)
        {
            timeElapsed = 0;
            active = false;
            return false;
        }
        return true;
    }

    virtual void run() = 0;

private:
    int period;
    int endTime;
    int timeElapsed;
    bool active;
    bool periodic;
    bool limited;
};

#endif