#ifndef __SERVOMOTOR__
#define __SERVOMOTOR__

#include "ComponentImpl.h"

class ServoMotor : public ComponentImpl
{
public:
    using ComponentImpl::ComponentImpl;

public:
    virtual void close();
    virtual void open(int angle);
    virtual int getAngle();
};

#endif