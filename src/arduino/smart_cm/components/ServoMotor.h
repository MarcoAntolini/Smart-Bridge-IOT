#ifndef __SERVOMOTOR__
#define __SERVOMOTOR__

#include "ComponentImpl.h"

class ServoMotor : public ComponentImpl
{
public:
    using ComponentImpl::ComponentImpl;

public:
    virtual void open(int angle) = 0;
    virtual void close() = 0;
    virtual int getAngle() = 0;
};

#endif