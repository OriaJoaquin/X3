  #include <Servo.h>
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  pinMode(10,OUTPUT);
  myservo.attach(10); 
}

void loop() {
  // put your main code here, to run repeatedly:
  myservo.write(117);
  int angle;
      for(angle = 117; angle < 147; angle++)    // command to move from 0 degrees to 180 degrees 
      {                                  
          myservo.write(angle);                 //command to rotate the servo to the specified angle
          delay(20);                       
      } 
   
    delay(1000); 
    for(angle = 147; angle>=87; angle--)     // command to move from 180 degrees to 0 degrees 
    {                                
      myservo.write(angle);              //command to rotate the servo to the specified angle
      delay(20);                      
    } 
  
      delay(1000);
}
