#include "BrillaMe.h"


void setup() 
{
  unsigned char currentMillis = millis();
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  Serial.begin(9600);
  BT1.begin(9600);

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
  int i = 0, j, k;
  
  if(BT1.available() && !BTBusy)
  {
    BTBusy = true;
    BTdata = BT1.read();
    //Serial.write(BT1.read());
  }
  
  if(Serial.available())
    BT1.write(Serial.read());

  if(true)
  {
    switch(BTdata)
    {
      case DANCE_MODE:
      {
        currentMillisLed = millis();
        if (currentMillisLed - previousMillisLed > timeToActionDance)
        {
           dance();
           previousMillisLed = currentMillisLed;
        }
      }
      
      case EXIT: 
      {
        if(!isCharged)
        {
          
        }
      }
      
      case true:
      {
          /* currentMillisCell = millis();
        if (!isCharged && currentMillisCell - previousMillisCell > timeToActionCell)
        {
          actCell = bascule.get_units() * (-1);
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
              isCharged = true;
              BT1.write(actCell);
            }
          }
          else
          {
            countCell = 0;
            prevCell = actCell;
          }
          previousMillisCell = currentMillisCell;
        }
        */
        if (true)
        {
          currentMillisLed = millis();
          if (!finished && currentMillisLed - previousMillisLed > timeToActionLed)
          {
            lights_on();
            previousMillisLed = currentMillisLed;
          }
        }
        currentMillisServo = millis();
        if(finished && currentMillisServo - previousMillisServo > timeToActionServo)
        {
          if(isShiny)
          {
            angle++;
            if(angle < TOP_ANGLE)                                  
            {
               myservo.write(angle);
            }
            else
            {
              myservo.write(MIDDLE_ANGLE);
              isCharged = false;
              BTBusy = false;
              flagLed1 = true;
              finished = false;                      
              Serial.println("ES BRILLANTEEEE");
              BT1.write(isShiny);
            }
             
          }
          else
          {
             angle--;
             if(angle > BOTTOM_ANGLE) 
             {                                
               myservo.write(angle);                        
             }
             else
             {
              myservo.write(MIDDLE_ANGLE);
              isCharged = false;
              BTBusy = false;
              flagLed1 = true;
              finished = false; 
              Serial.println("OSCURITO");
              BT1.write(isShiny);
             }
          }
          previousMillisServo = currentMillisServo;
        }
      }
    }   
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


void lights_on()
{     
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
    }
        
    aveLed.clear();
    aveLdr1.clear();
    aveLdr2.clear();
    aveLdr3.clear();
    aveLdr4.clear();
  }
}
