#ifndef __WATERSYSTEM__
#define __WATERSYSTEM__

#include "..\AlarmState.h"
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
        alarmState = AlarmState::NORMAL_SITUATION;
        prevAlarmState = alarmState;
        lastBlink = millis();
        lastAlarmTick = millis();
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
    AlarmState alarmState;
    AlarmState prevAlarmState;
    long lastBlink;
    long lastAlarmTick;
    void normalTask();
    void preAlarmTask();
    void alarmTask();
    void checkPrevState();
};

#endif