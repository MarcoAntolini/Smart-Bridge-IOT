#ifndef __WATERSYSTEM__
#define __WATERSYSTEM__

#include "..\AlarmState.h"
#include "..\kernel\Task.h"
#include "..\components\Light.h"
#include "..\components\Sonar.h"
#include "..\components\Pot.h"
#include "..\components\Monitor.h"
#include "..\components\ServoMotor.h"
#include "..\components\Button.h"

class WaterSystem : public Task
{
public:
    WaterSystem(Light *ledB, Light *ledC, Pot *pot, Sonar *sonar, Monitor *monitor, ServoMotor *servoMotor, Button *button) : Task()
    {
        this->ledB = ledB;
        this->ledC = ledC;
        this->pot = pot;
        this->sonar = sonar;
        this->monitor = monitor;
        this->servoMotor = servoMotor;
        this->button = button;
        this->alarmState = AlarmState::NORMAL_SITUATION;
    };
    void run();
    void normalTask();
    void preAlarmTask();
    void alarmTask();

private:
    Light *ledB;
    Light *ledC;
    Pot *pot;
    Sonar *sonar;
    Monitor *monitor;
    ServoMotor *servoMotor;
    Button *button;
    AlarmState alarmState;
};

#endif