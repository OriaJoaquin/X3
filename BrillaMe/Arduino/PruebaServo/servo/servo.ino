#include <Servo.h>
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  pinMode(10,OUTPUT);
  myservo.attach(10); 
}

void loop() {
  // put your main code here, to run repeatedly:
  int angle;
  myservo.write(66);
  delay(2000); 
      for(angle = 66; angle < 105; angle++)    // command to move from 0 degrees to 180 degrees 
      {                                  
          myservo.write(angle);                 //command to rotate the servo to the specified angle
          delay(5);                       
      } 
   
    delay(1000); 
    for(angle = 105; angle>=34; angle--)     // command to move from 180 degrees to 0 degrees 
    {                                
      myservo.write(angle);              //command to rotate the servo to the specified angle
      delay(5);                       
    } 
  
      delay(1000);
}
