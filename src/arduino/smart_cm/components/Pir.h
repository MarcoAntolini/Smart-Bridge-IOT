#ifndef __PIR__
#define __PIR__

#include "Component.h"

class Pir : public Component
{
public:
    using Component::Component;
    bool isDetected();
};

#endif