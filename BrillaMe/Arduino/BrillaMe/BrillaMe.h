#ifndef BrillaMe_h
#define BrillaMe_h
 
#include "Arduino.h"
#include <Servo.h>
#include <Average.h>
#include "HX711.h"
#include "String.h"


const char EXIT = '0'; 
const char BEGIN_RECOGNIZING = '1';
const char DANCE_MODE = '2';
const char LIGHTS_ON = '3';
const char LIGHTS_OUT = '4';
const char EMPTY_SHINY = '5';
const char EMPTY_NONSHINY = '6';
const char BEGIN_PATTERN = '7';
const char MOVE_SERVO = '8';
const char CHECK_IR = '9';
const char MOVE_LEFT = 'A';
const char MOVE_RIGHT = 'B';
const char MOVE_MIDDLE = 'C';

#define SCALE 211000
#define MIN_DEVIATION 0.01
#define OBJECT_DETECTED 20
#define MIDDLE_ANGLE 94//94
#define BOTTOM_ANGLE 74
#define TOP_ANGLE 124
#define MAX_INTENSITY 255
#define MIN_SHINY_DEVIATION 70
#define LED1 6 
#define LED2 4 
#define LED3 7 
#define LED4 11
#define LDR1 A0 
#define LDR2 A1 
#define LDR3 A2 
#define LDR4 A3
#define SERVO 10
#define SHINY_BASK 8
#define NONSHINY_BASK 9

void dance();
void readldr(int);
void begin_pattern();
void move_servo();
void move_left();
void move_right();
void lights_on();
void lights_out();
void exits();
void move_middle();

int pinData = A4;
int pinClk = A5;
HX711 bascule;
Servo myservo;
int lednumber = 0, ledpin = LED1;
int cell = A4;
int angle = MIDDLE_ANGLE;
char servo_pos = 'c';
const short INTENSITY_VALUE = 4;

Average<float> aveLdr1(64);
Average<float> aveLdr2(64);
Average<float> aveLdr3(64);
Average<float> aveLdr4(64);
Average<float> aveLed(16);


boolean flagLed1, flagLed2, flagLed3, flagLed4, finished;
int intensity;
unsigned long previousMillisCell = 0, currentMillisCell = 0;
unsigned long previousMillisLed = 0 , currentMillisLed = 0;
unsigned long previousMillisServo = 0, currentMillisServo = 0;
unsigned long previousMillisInfrared = 0, currentMillisInfrared= 0;
unsigned long timeToActionServo = 5;
unsigned long timeToActionCell = 50;
unsigned long timeToActionLed = 40;
unsigned long timeToActionDance = 250;
unsigned long timeToActionInfrared = 3000;
int waiting_drop = 0;
float prevCell = 0, actCell = 0;
const float minTolerance = 0.02;
int countCell;
boolean isShiny = false, isCellCharged = false, BTBusy = false;
boolean ShinyBaskFull = false, NonShinyBaskFull = false, detectIR = false;
int BTdata = 0; 
String Output;

 
#endif
