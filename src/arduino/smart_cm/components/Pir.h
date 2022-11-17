#ifndef __PIR__
#define __PIR__

#include "Component.h"

class Pir : public Component
{
public:
    using Component::Component;
    virtual bool isDetected();
};

#endif