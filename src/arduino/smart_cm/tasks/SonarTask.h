#include "..\kernel\Task.h"
#include "..\components\Sonar.h"

class SonarTask : public Task
{
public:
    SonarTask(Sonar *sonar) : Task() { this->sonar = sonar; };
    void run();

private:
    Sonar *sonar;
    float distance;
};