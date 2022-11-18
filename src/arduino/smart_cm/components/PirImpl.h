#ifndef __PIRIMPL__
#define __PIRIMPL__

#include "Pir.h"

class PirImpl : public Pir
{
public:
    using Pir::Pir;
    bool isDetected();
    long getLastSyncTime();

private:
    long lastSyncTime;
};

#endif