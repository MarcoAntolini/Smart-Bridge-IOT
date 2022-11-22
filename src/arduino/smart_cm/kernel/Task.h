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

    virtual void initPeriodic(long period)
    {
        this->active = true;
        this->periodic = true;
        this->limited = false;
        this->period = period;
        this->lastTick = millis();
    }

    virtual void initLimited(long endTime)
    {
        this->active = true;
        this->periodic = false;
        this->limited = true;
        this->endTime = endTime;
        this->startTime = millis();
    }

    void setPeriod(long period)
    {
        this->period = period;
    }

    long getPeriod()
    {
        return this->period;
    }

    void setActive(bool status)
    {
        active = status;
        lastTick = millis();
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

    bool checkPeriod()
    {
        if ((millis() - lastTick) >= period)
        {
            lastTick = millis();
            return true;
        }
        return false;
    }

    bool checkLimit()
    {
        if ((millis() - startTime) >= endTime)
        {
            startTime = millis();
            active = false;
            return false;
        }
        return true;
    }

    virtual void run() = 0;

private:
    long period;
    long endTime;
    long startTime;
    long lastTick;
    bool active;
    bool periodic;
    bool limited;
};

#endif