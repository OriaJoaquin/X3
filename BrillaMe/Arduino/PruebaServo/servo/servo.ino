  #include <Servo.h>
Servo myservo;
int asd = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(10,OUTPUT);
  myservo.attach(10); 
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  asd = Serial.read();
  if(asd == 1)
  myservo.write(150);
  else if (asd == 2)
  myservo.write(100);
  else if (asd == 3)
  myservo.write(50);
/*  int angle;
      for(angle = 117; angle < 147; angle++)    // command to move from 0 degrees to 180 degrees 
      {                                  
          myservo.write(angle);                 //command to rotate the servo to the specified angle
          delay(15);                       
      } 
   
    delay(1000); 
    for(angle = 147; angle>=87; angle--)     // command to move from 180 degrees to 0 degrees 
    {                                
      myservo.write(angle);              //command to rotate the servo to the specified angle
      delay(15);                      
    } 
  
      delay(1000);*/
}
