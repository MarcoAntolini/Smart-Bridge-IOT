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
        manualMode = false;
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
    bool manualMode;
    void normalTask();
    void preAlarmTask();
    void alarmTask();
    void checkPrevState();
    static void buttonInterrupt()
    {
        manualMode = !manualMode;
    };
};

#endif