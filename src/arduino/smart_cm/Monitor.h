#ifndef __MONITOR__
#define __MONITOR__

#include "Component.h"
#include <string>
using namespace std;

class Monitor : public Component
{
public:
    using Component::Component;
    void showMessage();
};

#endif