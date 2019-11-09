#include <Servo.h>
#include <Average.h>
#include "HX711.h"


int pinData = A4;
int pinClk = A5;
HX711 bascula;

void readldr(int, int);
void procesar();
Servo myservo;
int led1 = 6;
int led2 = 9;
int led3 = 10;
int led4 = 11;
int ldr1 = A0;
int ldr2 = A1;
int ldr3 = A2;
int ldr4 = A3;
int celda = A4;
const short VALOR_INTENSIDAD = 4;
const short CANT_MEDIDAS = 64;
Average<float> aveLdr1(64);
Average<float> aveLdr2(64);
Average<float> aveLdr3(64);
Average<float> aveLdr4(64);


boolean flagLed1, flagLed2, flagLed3, flagLed4, termino;
int intensidad;
int previousMillisCell = 0, currentMillisCell = 0;
int previousMillisLed = 0 , currentMillisLed = 0;
int timeToActionCell = 50;
int timeToActionLed = 40;
float prevCell = 0, actCell = 0;
const float minTolerance = 0.02;
int countCell;
boolean isShiny = false, isCharged = false;

// the setup function runs once when you press + reset or power the board
void setup() {
  unsigned char currentMillis = millis();
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(3, OUTPUT);

  Serial.begin(9600);

  flagLed1 = true;
  flagLed2 = false;
  flagLed3 = false;
  flagLed4 = false;
  termino = false;
  /*myservo.attach(3);
    myservo.write(90);*/

  bascula.begin(pinData, pinClk);
  bascula.set_scale(211000);
  bascula.tare();
  long zero_factor = bascula.read_average();
}


// the loop function runs over and over again forever
void loop() {
  int i, j, k;
  int angle;
  currentMillisLed = millis();
  currentMillisCell = millis();

  if (!isCharged && currentMillisCell - previousMillisCell > timeToActionCell)
  {
    actCell = bascula.get_units() * (-1);
    Serial.print("Leyendo: ");
    Serial.print(actCell, 3);
    Serial.print(" kgs");
    Serial.println();
    if(actCell < (prevCell + 0.01) && actCell > (prevCell - 0.01))
    {
      if (actCell > minTolerance)
      countCell++;
      if (countCell == 100)
      {
        isCharged = true;
      }
    }
    else
    {
      countCell = 0;
      prevCell = actCell;
    }
    previousMillisCell = currentMillisCell;
  }

  if (currentMillisLed - previousMillisLed > timeToActionLed)
  {
    /*  for(angle = 0; angle < 180; angle += 1)    // command to move from 0 degrees to 180 degrees
      {
      myservo.write(angle);                 //command to rotate the servo to the specified angle
      delay(5);
      }

      delay(1000);
      for(angle = 180; angle>=1; angle-=5)     // command to move from 180 degrees to 0 degrees
      {
      myservo.write(angle);              //command to rotate the servo to the specified angle
      delay(5);
      }
    */


    if (isCharged)
    {
      if (flagLed1)
      {
        intensidad += VALOR_INTENSIDAD;
        readldr(led1, 0);
        if (intensidad == 256)
        {
          flagLed1 = false;
          flagLed2 = true;
          intensidad = 0;

          Serial.println("///////////LED 1:   ");
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
          
          aveLdr1.clear();
          aveLdr2.clear();
          aveLdr3.clear();
          aveLdr4.clear();
    
        }
      }
      if(flagLed2)
      {
        intensidad += VALOR_INTENSIDAD;
        readldr(led2,1);
        if(intensidad == 256)
        {
          flagLed2 = false;
          flagLed3 = true;
          intensidad = 0;
  
          Serial.println("");
          Serial.println("");
          Serial.println("///////////LED 2:   ");
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
          
          aveLdr1.clear();
          aveLdr2.clear();
          aveLdr3.clear();
          aveLdr4.clear();        
        }
      }
      if(flagLed3)
      {
        intensidad += VALOR_INTENSIDAD;
        readldr(led3,2);
        if(intensidad == 256)
        {
          flagLed3 = false;
          flagLed4 = true;
          intensidad = 0;
  
          Serial.println("");
          Serial.println("");
          Serial.println("///////////LED 3:   ");
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
          
          aveLdr1.clear();
          aveLdr2.clear();
          aveLdr3.clear();
          aveLdr4.clear();
        }
      }
      if(flagLed4)
      {
        intensidad += VALOR_INTENSIDAD;
        readldr(led4,3);
        if(intensidad == 256)
        {
          flagLed4 = false;
          termino = true;
          intensidad = 0;
          procesar();
  
          Serial.println("");
          Serial.println("");
          Serial.println("///////////LED 4:   ");
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
          
          aveLdr1.clear();
          aveLdr2.clear();
          aveLdr3.clear();
          aveLdr4.clear();
        }
      }
    }

    previousMillisLed = currentMillisLed;
  }


  /*   if(isShiny) // si es brillante...
     {

     }
     else        // si no es brillante...
     {

     }
     isCharged = false;
    }
    /* if(currentMillis - previousMillis >= timeToAction)
  *//* {
   analogWrite(led1,255);
   analogWrite(led2,255);
   analogWrite(led3,255);
   analogWrite(led4,255);
  }*/
  /*
    Serial.println("ldr1");
    Serial.println(analogRead(ldr1));
    Serial.println("ldr2");
    Serial.println(analogRead(ldr2));
    Serial.println("ldr3");
    Serial.println(analogRead(ldr3));
    Serial.println("ldr4");
    Serial.println(analogRead(ldr4));

    delay(10000);
    /*for (int i=0; i<=255; i++){
      analogWrite(ledPin, i);
      delay(100);
    }
    for (int i=255; i>=0; i--) {
      analogWrite(ledPin, i);
      delay(100);
    }*/
}

void readldr(int led, int posled)
{

  analogWrite(led, intensidad);



  aveLdr1.push(analogRead(ldr1));
  aveLdr2.push(analogRead(ldr2));
  aveLdr3.push(analogRead(ldr3));
  aveLdr4.push(analogRead(ldr4));

  /*
    Serial.print("LED:  ");
    Serial.print(posled);
    Serial.print("  Indice  ");
    Serial.print(indice);
    Serial.print("  Valor ");
    Serial.println(dataldr1[posled][indice]);
  */

  if (intensidad >= 256) // APAGAMOS EL LED
  {
    analogWrite(led, 0);
  }
}

void procesar() {


  //Serial.print("Media ldr 2:   ");
  // Serial.println(aveLdr2.mean());

}
