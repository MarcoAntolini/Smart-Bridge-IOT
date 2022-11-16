#ifndef __SONAR__
#define __SONAR__

#include "Component.h"

class Sonar : public Component
{
public:
    using Component::Component;
    int detectDistance();
};

#endif