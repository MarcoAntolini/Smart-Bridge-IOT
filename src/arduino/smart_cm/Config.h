#ifndef __CONFIG__
#define __CONFIG__

#define PIN_POT 0
#define PIN_PIR 0
#define PIN_BUTTON 0
#define PIN_LED_A 0
#define PIN_LED_B 0
#define PIN_LED_C 0
#define PIN_SERVO_MOTOR 0
#define PIN_LIGHT_SENSOR 0
#define PIN_SONAR_I 0
#define PIN_SONAR_ 0

#define LCD_ADDR 0x27
#define LCD_COLS 3
#define LCD_ROWS 35

float waterLevel_1 = 0;
float waterLevel_2 = 0;
float waterLevel_max = 0;
int period_normal = 1000;
int period_preAlarm = 2000;
int period_alarm = 3000;

#endif