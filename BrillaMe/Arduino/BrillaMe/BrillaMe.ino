#include "BrillaMe.h"


void setup() 
{
  unsigned char currentMillis = millis();
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(IR_SHINY, INPUT);
  pinMode(IR_NONSHINY, INPUT);

  Serial.begin(9600);
  Serial1.begin(9600);

  flagLed1 = true;
  flagLed2 = false;
  flagLed3 = false;
  flagLed4 = false;
  finished = false;
  myservo.attach(SERVO);
  myservo.write(MIDDLE_ANGLE);
  bascule.begin(pinData, pinClk);
  bascule.set_scale(SCALE);
  bascule.tare();
  long zero_factor = bascule.read_average();
  pinMode(11, OUTPUT);
}


void loop() 
{
  if ( Serial1.available() && !BTBusy) 
  { 
    BTdata = Serial1.read();
    Serial.write( BTdata );
    
  }
  if ( Serial.available() && !BTBusy)
  {
    BTdata = Serial.read();
  }
  

  switch(BTdata)
  {
    case DANCE_MODE: 
    if(!BTBusy) 
      dance();
    break;
    
    case EXIT: 
      exits(); 
    break;
    
    case BEGIN_RECOGNIZING:
      detect_weight();
    break;

    case BEGIN_PATTERN: 
      begin_pattern();
    break;

    case MOVE_SERVO:
      move_servo();
    break;

    case CHECK_IR: 
      check_infrared();
    break;
    
    case MOVE_LEFT: 
      move_left();
    break;
    
    case MOVE_RIGHT:
      move_right();
    break;

    case MOVE_MIDDLE:
      move_middle();
    break;
    
    case EMPTY_SHINY:
      ShinyBaskFull = false;
    break;
    
    case EMPTY_NONSHINY:
      NonShinyBaskFull = false;
    break;

    case LIGHTS_ON: 
      lights_on();
    break;

    case LIGHTS_OUT: 
      lights_out();
    break;
      

    default:
      BTBusy = false;
  }
}


void readldr(int led)
{
  analogWrite(led, intensity);
  Serial.write(led);
  aveLdr1.push(analogRead(LDR1));
  aveLdr2.push(analogRead(LDR2));
  aveLdr3.push(analogRead(LDR3));
  aveLdr4.push(analogRead(LDR4));

  if (intensity >= MAX_INTENSITY)
  {
    analogWrite(led, 0);
  }
}


void dance()
{
  currentMillisLed = millis();
  if (currentMillisLed - previousMillisLed > timeToActionDance)
  {
    previousMillisLed = currentMillisLed;
    
    if(ledpin == LED1)
    {
      analogWrite(LED4,0);
      analogWrite(LED1,MAX_INTENSITY);
      ledpin = LED2;  
    }
    else if(ledpin == LED2)
    {
      analogWrite(LED1, 0);
      analogWrite(LED2,MAX_INTENSITY);
      ledpin = LED3;
    }
    
    else if(ledpin == LED3)
    {
      analogWrite(LED2, 0);
      analogWrite(LED3,MAX_INTENSITY);
      ledpin = LED4;
    }
    else
    {
      analogWrite(LED3,0);
      analogWrite(LED4,MAX_INTENSITY);
      ledpin = LED1;
    }
  }
}


void begin_pattern()
{ 
  currentMillisLed = millis();
  if (currentMillisLed - previousMillisLed > timeToActionLed)
  {
    previousMillisLed = currentMillisLed;    
    intensity += INTENSITY_VALUE;
    readldr(ledpin);
    if(intensity >= MAX_INTENSITY)
    {
      Serial.println("");
      Serial.println("");
      Serial.print("///////////LED ");
      Serial.print(lednumber +1);
      Serial.println(":    ");
      Serial.print("Media LDR1   ");    
      Serial.println(aveLdr1.mean());
      Serial.print("Media LDR2   ");
      Serial.println(aveLdr2.mean());
      Serial.print("Media LDR3   ");
      Serial.println(aveLdr3.mean());
      Serial.print("Media LDR4   ");
      Serial.println(aveLdr4.mean());
  
      Serial.print("Desvio LDR1   "); 
      Serial.println(aveLdr1.stddev());
      Serial.print("Desvio LDR2   "); 
      Serial.println(aveLdr2.stddev());
      Serial.print("Desvio LDR3   "); 
      Serial.println(aveLdr3.stddev());
      Serial.print("Desvio LDR4   "); 
      Serial.println(aveLdr4.stddev());
  
      aveLed.push(aveLdr1.stddev());
      aveLed.push(aveLdr2.stddev());
      aveLed.push(aveLdr3.stddev());
      aveLed.push(aveLdr4.stddev());
      lednumber++;
      intensity = 0;
      if(ledpin == LED1)
        ledpin = LED2;
      else if(ledpin == LED2)
        ledpin = LED3;
      else if(ledpin == LED3)
        ledpin = LED4;
      else
      {
        finished = true;
        BTdata = MOVE_SERVO;
        intensity = 0;
        lednumber = 0;
        ledpin = LED1;  
      }
    
      if(finished)
      {
        Serial.println("------ TOTAL ------ ");
        Serial.print("Media de desvio: ");
        Serial.println(aveLed.mean());
       if(aveLed.mean() > MIN_SHINY_DEVIATION)
         isShiny = true;
       else
         isShiny = false;
       BTdata = MOVE_SERVO;
      }
          
      aveLed.clear();
      aveLdr1.clear();
      aveLdr2.clear();
      aveLdr3.clear();
      aveLdr4.clear();
    }
  }
}

void move_servo()
{
  currentMillisServo = millis();
  if(currentMillisServo - previousMillisServo > timeToActionServo)
  {
    previousMillisServo = currentMillisServo;
    if(isShiny)
    {
      Serial.println("Es brillante");
      angle++;
      Serial.println(angle);
      if(angle < TOP_ANGLE)                                  
      {
         myservo.write(angle);
         delay(10);
      }
      else
      {
        waiting_drop++;
        if(waiting_drop == 200)
        {
          myservo.write(MIDDLE_ANGLE);
          angle = MIDDLE_ANGLE;
          BTdata = CHECK_IR;
          waiting_drop = 0;
        }
      }   
    }
    else
    {
      Serial.println("Es No Brillante");
       angle--;
       if(angle > BOTTOM_ANGLE) 
       {                                
         myservo.write(angle);                      
       }
       else
       {
        waiting_drop++;
        if(waiting_drop == 200)
        {
          myservo.write(MIDDLE_ANGLE);
          angle = MIDDLE_ANGLE;
          BTdata = CHECK_IR;
          waiting_drop = 0;
        }
       }
    }
  }
}

void detect_weight()
{
  BTBusy = true;
  currentMillisCell = millis();
  if(currentMillisCell - previousMillisCell > timeToActionCell)
  {
    previousMillisCell = currentMillisCell; 
    actCell = bascule.get_units();
    Serial.print("Leyendo: ");
    Serial.print(actCell, 3);
    Serial.print("  kgs");
    Serial.println();
    if(actCell < (prevCell + MIN_DEVIATION) && actCell > (prevCell - MIN_DEVIATION))
    {
      if (actCell > minTolerance)
      countCell++;
      if (countCell == OBJECT_DETECTED)
      {
        BTdata = BEGIN_PATTERN;
      }
    }
    else
    {
      countCell = 0;
      prevCell = actCell;
    }
  }
}

void check_infrared()
{
  currentMillisInfrared = millis();
  if(currentMillisInfrared - previousMillisInfrared > timeToActionInfrared)
  {
    previousMillisInfrared = currentMillisInfrared;
    detectIR = false;
    isCellCharged = false;
    BTBusy = false;
    flagLed1 = true;
    finished = false;  
    BTdata = EXIT;         
    Serial1.println(isShiny);
    Serial1.println(actCell);         
    if(isShiny)
    {
      if(digitalRead(IR_SHINY) == HIGH)
        Serial1.println('1');
      else
        Serial1.println('0');    
    }
    else
    {
      if(digitalRead(IR_NONSHINY) == HIGH)
        Serial1.println('1');
      else
        Serial1.println('0'); 
    }
  } 
}

void move_left()
{
  BTBusy = true;
  currentMillisServo = millis();
  if(currentMillisServo - previousMillisServo > timeToActionServo)
  {
    angle++;
    previousMillisServo = currentMillisServo;
    if(angle < TOP_ANGLE)                                  
    {
      Serial.println(angle);
      myservo.write(angle);
      delay(0);
    }
    else  
    {
      BTBusy = false;
      BTdata = 0;
      servo_pos = 'l';
    }
  }
}

void move_right()
{
  BTBusy = true;
  currentMillisServo = millis();
  if(currentMillisServo - previousMillisServo > timeToActionServo)
  {
    previousMillisServo  = currentMillisServo;
    angle--;
    Serial.println(angle);
    if(angle > BOTTOM_ANGLE)                                  
    {
       myservo.write(angle);
       delay(0);
    }
    else
    {
      BTBusy = false;
      BTdata = 0;
      servo_pos = 'r';
    }
  }
}

void move_middle()
{
  BTBusy = true;
  currentMillisServo = millis();
  if(currentMillisServo - previousMillisServo > timeToActionServo)
  {
    previousMillisServo  = currentMillisServo;
    if(servo_pos == 'l')
      angle--;
    else
      angle++;
    if(angle != MIDDLE_ANGLE)                                  
    {
       myservo.write(angle);
       delay(0);
    }
    else
    {
      BTBusy = false;
      BTdata = 0;
      servo_pos = 'c';
    }
  }
}

void lights_on()
{
  analogWrite(LED1,MAX_INTENSITY);
  analogWrite(LED2,MAX_INTENSITY);
  analogWrite(LED3,MAX_INTENSITY);
  analogWrite(LED4,MAX_INTENSITY);
}

void lights_out()
{
  analogWrite(LED1,0);
  analogWrite(LED2,0);
  analogWrite(LED3,0);
  analogWrite(LED4,0);
}

void exits()
{
  if(!BTBusy)
  {
    analogWrite(LED1,0);
    analogWrite(LED2,0);
    analogWrite(LED3,0);
    analogWrite(LED4,0);
  }
}
