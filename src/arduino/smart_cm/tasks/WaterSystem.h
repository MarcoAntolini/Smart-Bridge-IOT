#ifndef __WATERSYSTEM__
#define __WATERSYSTEM__

#include "..\Config.h"
#include "..\State.h"
#include "..\kernel\Task.h"
#include "..\components\led\LedImpl.h"
#include "..\components\sonar\SonarImpl.h"
#include "..\components\pot\PotImpl.h"
#include "..\components\monitor\MonitorImpl.h"
#include "..\components\servoMotor\ServoMotorImpl.h"
#include "..\components\button\ButtonImpl.h"
#include "LightSystem.h"

class WaterSystem : public Task
{
public:
    WaterSystem(Light *ledB, Light *ledC, Pot *pot, Sonar *sonar, Monitor *monitor, ServoMotor *servoMotor, Button *button, LightSystem *lightSystem) : Task()
    {
        this->ledB = ledB;
        this->ledC = ledC;
        this->pot = pot;
        this->sonar = sonar;
        this->monitor = monitor;
        this->servoMotor = servoMotor;
        this->button = button;
        this->lightSystem = lightSystem;
        state = State::NORMAL_SITUATION;
        prevState = state;
        lastBlink = millis();
        lastAlarmTick = millis();
        distance = maxDistance;
    };
    void run();

private:
    Light *ledB;
    Light *ledC;
    Pot *pot;
    Sonar *sonar;
    Monitor *monitor;
    ServoMotor *servoMotor;
    Button *button;
    LightSystem *lightSystem;
    State state;
    State prevState;
    long lastBlink;
    long lastAlarmTick;
    float distance;
    void normalTask();
    void preAlarmTask();
    void alarmTask();
    void checkPrevState();
};

#endif