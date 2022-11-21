#include "SonarTask.h"
#include "..\Config.h"

// SonarTask::SonarTask(int period, Sonar *sonar) : Task(period)
// {
//     this->sonar = sonar;
// }

void SonarTask::run()
{
    distance = sonar->detectDistance();
    if (distance < waterLevel_1)
    {
        this->setPeriod(period_alarm);
    }
    else if (distance < waterLevel_2)
    {
        this->setPeriod(period_preAlarm);
    }
    else if (distance < waterLevel_max)
    {
        this->setPeriod(period_normal);
    }
}