#include "..\kernel\Task.h"
#include "..\components\Sonar.h"

class SonarTask : public Task
{
public:
    SonarTask(int period, Sonar *sonar) : Task(period) { this->sonar = sonar; };
    void run();

private:
    Sonar *sonar;
    float distance;
};