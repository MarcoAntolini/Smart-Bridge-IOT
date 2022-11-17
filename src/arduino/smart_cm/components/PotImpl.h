#ifndef __POTIMPL__
#define __POTIMPL__

#include "Pot.h"

class PotImpl : public Pot
{
public:
    using Pot::Pot;
    int getValue();
};

#endif
