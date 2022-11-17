#ifndef __SONARIMPL__
#define __SONARIMPL__

#include "Sonar.h"

class SonarImpl : public Sonar
{
public:
    using Sonar::Sonar;
    int detectDistance();
};

#endif