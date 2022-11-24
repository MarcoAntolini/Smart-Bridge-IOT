#include <Arduino.h>
#include "Config.h"
#include "components\led\LedImpl.h"
#include "components\button\ButtonImpl.h"
#include "components\pot\PotImpl.h"
#include "components\servoMotor\ServoMotorImpl.h"
#include "components\sonar\SonarImpl.h"
#include "components\pir\PirImpl.h"
#include "components\lightSensor\LightSensorImpl.h"
#include "components\monitor\MonitorImpl.h"
#include "kernel\Scheduler.h"
#include "tasks\LightSystem.h"
#include "tasks\WaterSystem.h"

Scheduler scheduler;

void setup()
{
    Serial.begin(9600);
    Light *ledA = new LedImpl(PIN_LED_A);
    Light *ledB = new LedImpl(PIN_LED_B);
    Light *ledC = new LedImpl(PIN_LED_C);
    Button *button = new ButtonImpl(PIN_BUTTON);
    Pot *pot = new PotImpl(PIN_POT);
    Pir *pir = new PirImpl(PIN_PIR);
    LightSensor *lightSensor = new LightSensorImpl(PIN_LIGHT_SENSOR);
    ServoMotor *servoMotor = new ServoMotorImpl(PIN_SERVO_MOTOR);
    Sonar *sonar = new SonarImpl(PIN_SONAR_I, PIN_SONAR_O);
    Monitor *monitor = new MonitorImpl(LCD_ADDR, LCD_COLS, LCD_ROWS);

    scheduler.init();
    monitor->init();

    LightSystem *lightSystem = new LightSystem(ledA, lightSensor, pir);
    lightSystem->init();
    scheduler.addTask(lightSystem);

    WaterSystem *waterSystem = new WaterSystem(ledB, ledC, pot, sonar, monitor, servoMotor, button, lightSystem);
    waterSystem->initPeriodic(period_normal);
    scheduler.addTask(waterSystem);
}

void loop()
{
    scheduler.schedule();
}