#include <Servo.h>

void readldr(int,int);
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
const char VALOR_INTENSIDAD = 4;
const char CANT_MEDIDAS = 64;
unsigned short dataldr[4][4][CANT_MEDIDAS] ={{{0}}};
boolean flagLed1, flagLed2, flagLed3, flagLed4, termino;
int intensidad;
int previousMillisCell = 0;
int timeToActionCell = 1000;
int timeToActionLed = 40;
int prevCell, actCell, prevLed = 0 , actLed = 0;
int minTolerance;
int countCell;
boolean isShiny = false;
// the setup function runs once when you press + reset or power the board
void setup() {
  unsigned char currentMillis = millis();
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(3,OUTPUT);
  Serial.begin(9600);
  flagLed1 = true;
  flagLed2 = false;
  flagLed3 = false;
  flagLed4 = false;
  termino = false;
  /*myservo.attach(3);
  myservo.write(90);*/
}

// the loop function runs over and over again forever
void loop() {
  int i,j,k;
  int angle;
  actLed = millis();
  if(actLed - prevLed > timeToActionLed)
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
  
      delay(1000);
    boolean isCharged = false;
    unsigned char currentMillis = millis();
    actCell = analogRead(celda);
    if(!isCharged && actCell > minTolerance)
    {
      if(actCell == prevCell)
      {
        countCell++;
      }
      else
      {
        countCell = 0;
        prevCell = actCell;
      }
      if(countCell == 10000)
      {
        isCharged = true; 
      }
    }
    if(isCharged)
    {  */
    if(flagLed1)
    {
      intensidad += VALOR_INTENSIDAD;
      readldr(led1,0);
      if(intensidad == 256)
      {
        flagLed1 = false;
        flagLed2 = true;
        intensidad = 0;
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
      }
    }

    
    
     prevLed= actLed;
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
      analogWrite(led,intensidad);
        dataldr[0][posled][intensidad] = analogRead(ldr1); 
        dataldr[1][posled][intensidad] = analogRead(ldr2); 
        dataldr[2][posled][intensidad] = analogRead(ldr3); 
        dataldr[3][posled][intensidad] = analogRead(ldr4); 
    if(intensidad >= 256)  // APAGAMOS EL LED
    {
      analogWrite(led,0);
    }
}

void procesar(){
  int k,j,i;
  short media[4][4] = {{0}}, varianza[4][4] = {{0}};
  long promedioVarianza = 0;
  
  //Sumamos valores para las medias
  for(k = 0; k < 4 ; k++)
  {
    for(i = 0; i < CANT_MEDIDAS; i++)
    {
      media[0][k] = media[0][k] + dataldr[0][k][i];
      media[1][k] = media[1][k] + dataldr[1][k][i];
      media[2][k] = media[2][k] + dataldr[2][k][i];
      media[3][k] = media[3][k] + dataldr[3][k][i];
    }

       
    //Dividimos para obtener la media
    media[0][k] = media[0][k] / CANT_MEDIDAS;
    media[1][k] = media[1][k] / CANT_MEDIDAS;
    media[2][k] = media[2][k] / CANT_MEDIDAS;
    media[3][k] = media[3][k] / CANT_MEDIDAS;
  }


  //Calculamos las 16 varianzas
  for(k = 0; k < 4 ; k++)
  {
    for(i = 0; i < CANT_MEDIDAS; i++)
    {
      varianza[0][k] = varianza[0][k] + ((dataldr[0][k][i] - media[0][k])*(dataldr[0][k][i] - media[0][k]));
      varianza[1][k] = varianza[1][k] + ((dataldr[1][k][i] - media[1][k])*(dataldr[1][k][i] - media[1][k]));
      varianza[2][k] = varianza[2][k] + ((dataldr[2][k][i] - media[2][k])*(dataldr[2][k][i] - media[2][k]));
      varianza[3][k] = varianza[3][k] + ((dataldr[3][k][i] - media[3][k])*(dataldr[3][k][i] - media[3][k]));
    }
    varianza[0][k] = varianza [0][k] / CANT_MEDIDAS;
    varianza[1][k] = varianza [1][k] / CANT_MEDIDAS;
    varianza[2][k] = varianza [2][k] / CANT_MEDIDAS;
    varianza[3][k] = varianza [3][k] / CANT_MEDIDAS;
    
    promedioVarianza += (varianza[0][k] + varianza[1][k] + varianza[2][k] + varianza[3][k]);
  }
  promedioVarianza = promedioVarianza / 16;
  
  Serial.print(promedioVarianza);
}
