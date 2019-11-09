#include <SoftwareSerial.h>

SoftwareSerial BT1(4,5); // RX | TX
int pinKEY = 3;
void setup()
{ 
  Serial.begin(9600);
  BT1.begin(9600); 
}

void loop()
{  
  if (BT1.available())
        Serial.write(BT1.read());
  if (Serial.available())
        BT1.write(Serial.read());
}
