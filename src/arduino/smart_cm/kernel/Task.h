#ifndef __TASK__
#define __TASK__

class Task
{
public:
    Task(int period)
    {
        this->period = period;
        this->timeElapsed = 0;
        this->active = false;
    }

    void setPeriod(int period)
    {
        this->period = period;
    }

    void setActive(bool status)
    {
        this->active = active;
    }

    bool isActive()
    {
        return this->active;
    }

    bool update(int period)
    {
        this->timeElapsed += period;
        if (this->timeElapsed >= this->period)
        {
            this->timeElapsed = 0;
            return true;
        }
        else
        {
            return false;
        }
    }

    virtual void run() = 0;

private:
    int period;
    int timeElapsed;
    bool active;
};

#endif