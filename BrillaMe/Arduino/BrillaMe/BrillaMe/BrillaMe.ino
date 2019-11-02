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
unsigned short dataldr1[4][CANT_MEDIDAS] ={{0}};
unsigned short dataldr2[4][CANT_MEDIDAS] ={{0}};
unsigned short dataldr3[4][CANT_MEDIDAS] ={{0}};
unsigned short dataldr4[4][CANT_MEDIDAS] ={{0}};

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

    
    
     prevLed = actLed;
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
    int indice;
    analogWrite(led,intensidad);

    indice = (intensidad / 4) - 1;
    dataldr1[posled][indice] = analogRead(ldr1); 
    dataldr2[posled][indice] = analogRead(ldr2); 
    dataldr3[posled][indice] = analogRead(ldr3); 
    dataldr4[posled][indice] = analogRead(ldr4); 

    /*
    Serial.print("LED:  ");
    Serial.print(posled);
    Serial.print("  Indice  ");
    Serial.print(indice);
    Serial.print("  Valor ");
    Serial.println(dataldr1[posled][indice]);
    */
    
    if(intensidad >= 256)  // APAGAMOS EL LED
    {
      analogWrite(led,0);
    }
}

void procesar(){
  int k,j,i;
  unsigned short media1[4] = {0};
  unsigned short media2[4] = {0};
  unsigned short media3[4] = {0};
  unsigned short media4[4] = {0};
  
  unsigned short varianza1[4] = {0};
  unsigned short varianza2[4] = {0};
  unsigned short varianza3[4] = {0};
  unsigned short varianza4[4] = {0};

  

  int promedioVar = 0;
  
  //Sumamos valores para las medias
  for(k = 0; k < 4 ; k++)
  {
    
    for(i = 0; i < CANT_MEDIDAS; i++)
    {
      media1[k] = media1[k] + dataldr1[k][i];
      media2[k] = media2[k] + dataldr2[k][i];
      media3[k] = media3[k] + dataldr3[k][i];
      media4[k] = media4[k] + dataldr4[k][i];
/*
      Serial.print("LED:  ");
    Serial.print(k);
    Serial.print("  Indice  ");
    Serial.print(i);
    Serial.print("  Valor ");
    Serial.println(dataldr1[k][i]);
*/

    }
    //Serial.println(media1[k]);
       
    //Dividimos para obtener la media
    media1[k] = media1[k] / CANT_MEDIDAS;
    media2[k] = media2[k] / CANT_MEDIDAS;
    media3[k] = media3[k] / CANT_MEDIDAS;
    media4[k] = media4[k] / CANT_MEDIDAS;

    Serial.println(media1[k]);
  }

//Serial.println(media1[0]);
  //Calculamos las 16 varianzas
  for(k = 0; k < 4 ; k++)
  {
    for(i = 0; i < CANT_MEDIDAS; i++)
    {
      varianza1[k] = varianza1[k] + ((dataldr1[k][i] - media1[k])*(dataldr1[k][i] - media1[k]));
      varianza2[k] = varianza2[k] + ((dataldr2[k][i] - media2[k])*(dataldr2[k][i] - media2[k]));
      varianza3[k] = varianza3[k] + ((dataldr3[k][i] - media3[k])*(dataldr3[k][i] - media3[k]));
      varianza4[k] = varianza4[k] + ((dataldr4[k][i] - media4[k])*(dataldr4[k][i] - media4[k]));
    }
    varianza1[k] = varianza1[k] / CANT_MEDIDAS;
    varianza2[k] = varianza2[k] / CANT_MEDIDAS;
    varianza3[k] = varianza3[k] / CANT_MEDIDAS;
    varianza4[k] = varianza4[k] / CANT_MEDIDAS;
    
    promedioVar = promedioVar + (varianza1[k] + varianza2[k] + varianza3[k] + varianza4[k]);
  }
  promedioVar = promedioVar / 16;
  
  //Serial.println(promedioVar); 
}
