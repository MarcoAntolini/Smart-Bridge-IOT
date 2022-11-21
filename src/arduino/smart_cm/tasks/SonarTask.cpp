#include "SonarTask.h"

// SonarTask::SonarTask(int period, Sonar *sonar) : Task(period)
// {
//     this->sonar = sonar;
// }

void SonarTask::run()
{
    distance = sonar->detectDistance();
    if (distance < 0.5)
    {
        this->setPeriod(3000);
    }
    else if (distance < 1.0)
    {
        this->setPeriod(2000);
    }
    else
    {
        this->setPeriod(1000);
    }
}