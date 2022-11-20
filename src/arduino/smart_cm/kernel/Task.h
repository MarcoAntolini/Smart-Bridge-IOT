#ifndef __TASK__
#define __TASK__

class Task
{
public:
    Task()
    {
        active = false;
    }

    virtual bool isActive()
    {
        return active;
    }

    virtual void run();

private:
    bool active;
    bool play;
};

#endif