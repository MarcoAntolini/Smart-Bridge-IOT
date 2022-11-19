#ifndef __TASK__
#define __TASK__

class Task
{
public:
    Task()
    {
        active = false;
        play = false;
    }

    virtual bool isActive()
    {
        return active;
    }

    virtual bool isPlay()
    {
        return play;
    }

private:
    bool active;
    bool play;
};

#endif