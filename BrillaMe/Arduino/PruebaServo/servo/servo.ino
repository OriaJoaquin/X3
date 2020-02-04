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
  myservo.write(95);
  // medio 95
  // izquieda 78
  // derecha 112
  
/*  int angle;95
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
