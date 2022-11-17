#ifndef __TASK__
#define __TASK__

class Task
{
private:
    bool active;
    bool play;
public:
    task(){
        active = false;
        play = false;
    }

    virtual bool isActive(){
        return active;
    }

    virtual bool isPlay(){
        return play;
    }

};


#endif