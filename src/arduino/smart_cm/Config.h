#ifndef __CONFIG__
#define __CONFIG__

#include "Arduino.h"

#define PIN_POT 0
#define PIN_PIR 0
#define PIN_BUTTON 0
#define PIN_LED_A 0
#define PIN_LED_B 0
#define PIN_LED_C 0
#define PIN_SERVO_MOTOR 0
#define PIN_LIGHT_SENSOR 0
#define PIN_SONAR_I 0
#define PIN_SONAR_O 0

#define LCD_ADDR 0x27
#define LCD_COLS 3
#define LCD_ROWS 35

#define MAX_TASKS 20

const float waterLevel_1 = 33;
const float waterLevel_2 = 66;
const float waterLevel_max = 100;
const long period_normal = 3000;
const long period_preAlarm = 2000;
const long period_alarm = 1000;

const int lightTreshold = 0;
const int lightTimer = 0;

const long blinkDelay = 2000;

const int debounceDelay = 50;

const int maxDistance = 30;

const String alarm = "Alarm Situation";
const String preAlarm = "Pre Alarm Situation";
const String water = "Current water level: ";
const String valves = "Current valves opening degrees: ";

#endif