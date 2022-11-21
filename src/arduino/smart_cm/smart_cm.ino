#include <Arduino.h>
#include "Config.h"
#include "components\Light.h"
#include "components\Button.h"
#include "components\Pot.h"
#include "components\ServoMotor.h"
#include "components\Sonar.h"
#include "components\Pir.h"
#include "components\LightSensor.h"
#include "components\Monitor.h"
#include "kernel\Scheduler.h"
#include "tasks\LightSystem.h"

Scheduler scheduler;

void setup()
{
    Light *ledA = new LedImpl(PIN_LED_A);
    Light *ledB = new LedImpl(PIN_LED_B);
    Light *ledC = new LedImpl(PIN_LED_C);
    Button *button = new ButtonImpl(PIN_BUTTON);
    Pot *pot = new PotImpl(PIN_POT);
    Pir *pir = new PirImpl(PIN_PIR);
    LightSensor *lightSensor = new LightSensorImpl(PIN_LIGHT_SENSOR);
    ServoMotor *servoMotor = new ServoMotorImpl(PIN_SERVO_MOTOR);
    Sonar *sonar = new SonarImpl(PIN_SONAR_I, PIN_SONAR_O);
    Monitor *monitor = new Monitorimpl(LCD_ADDR, LCD_COLS, LCD_ROWS);

    scheduler.init(0);

    Task *lightSystem = new LightSystem(ledA, lightSensor, pir);
    lightSystem->init();
    scheduler.addTask(lightSystem);
}

void loop()
{
    scheduler.schedule();
}