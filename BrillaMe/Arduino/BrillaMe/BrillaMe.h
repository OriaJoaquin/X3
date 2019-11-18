#ifndef BrillaMe_h
#define BrillaMe_h
 
#include "Arduino.h"
#include <Servo.h>
#include <Average.h>
#include "HX711.h"
#include <SoftwareSerial.h>

#define EXIT 0 
#define BEGIN_RECOGNIZING 1
#define DANCE_MODE 2
#define MOVE_LEFT 3
#define MOVE_RIGHT 4
#define SCALE 211000
#define MIN_DEVIATION 0.01
#define OBJECT_DETECTED 100
#define MIDDLE_ANGLE 57
#define BOTTOM_ANGLE 30
#define TOP_ANGLE 90
#define MAX_INTENSITY 255
#define MIN_SHINY_DEVIATION 70
#define LED1 6 
#define LED2 3 
#define LED3 7 
#define LED4 11
#define LDR1 A0 
#define LDR2 A1 
#define LDR3 A2 
#define LDR4 A3
#define SERVO 10

void dance();
void readldr(int);
void lights_on();

int pinData = A4;
int pinClk = A5;
HX711 bascule;
Servo myservo;
int lednumber = 0, ledpin = LED1;
int cell = A4;
int angle = MIDDLE_ANGLE;
const short INTENSITY_VALUE = 4;

Average<float> aveLdr1(64);
Average<float> aveLdr2(64);
Average<float> aveLdr3(64);
Average<float> aveLdr4(64);
Average<float> aveLed(16);

SoftwareSerial BT1(4,5); // RX | TX

boolean flagLed1, flagLed2, flagLed3, flagLed4, finished;
int intensity;
int previousMillisCell = 0, currentMillisCell = 0;
int previousMillisLed = 0 , currentMillisLed = 0;
int previousMillisServo = 0, currentMillisServo = 0;
int timeToActionServo = 5;
int timeToActionCell = 50;
int timeToActionLed = 40;
int timeToActionDance = 250;
float prevCell = 0, actCell = 0;
const float minTolerance = 0.02;
int countCell;
boolean isShiny = false, isCharged = false, BTBusy = false;
int BTdata; 

 
#endif