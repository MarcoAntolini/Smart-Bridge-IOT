#ifndef __CONFIG__
#define __CONFIG__

#include <Arduino.h>

#define PIN_POT A0
#define PIN_PIR 6
#define PIN_BUTTON 3
#define PIN_LED_A 13
#define PIN_LED_B 12
#define PIN_LED_C 11
#define PIN_SERVO_MOTOR 9
#define PIN_LIGHT_SENSOR A1
#define PIN_SONAR_I 4
#define PIN_SONAR_O 5

// #define SDA A4
// #define SCL A5
#define LCD_ADDR 0x27
#define LCD_COLS 3
#define LCD_ROWS 35

#define MAX_TASKS 20

const float distancePreAlarm = 20;
const float distanceAlarm = 10;
const unsigned long period_normal = 3000;
const unsigned long period_preAlarm = 2000;
const unsigned long period_alarm = 1000;

const int lightTreshold = 60;
const int lightTimer = 10000;

const unsigned long blinkDelay = 2000;

const unsigned long debounceDelay = 40;

const int maxDistance = 30;

#endif