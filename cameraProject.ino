#include <Servo.h>
Servo Servo_X;
Servo Servo_Y;
int servoPinY = 10;
int servoPinX = 9;
int currentDegreeX=90;
int currentDegreeY=90;
int degreeX; 
int degreeY;
String cameraDegrees;
String X;
String Y;
void setup() {
 Servo_X.attach(servoPinX);
 Servo_Y.attach(servoPinY);
 Servo_X.write(currentDegreeX);
 Servo_Y.write(currentDegreeY);
 Serial.begin(9600);
}
void loop() {
  if(Serial.available()) // reads Data from the usb port
  {
    X ="";
    Y ="";
    cameraDegrees=Serial.readStringUntil('\n');
    int i;
    for(i = 1 ;cameraDegrees[i] != 'Y';i++)
    {
      X += cameraDegrees[i] ;
    }
    for( i=i+1; i < cameraDegrees.length() ;i++)
    {
      Y += cameraDegrees[i] ;
    }  
    degreeX = X.toInt();  
    degreeY = Y.toInt();
    currentDegreeX = currentDegreeX + (34.25 - degreeX);
    currentDegreeY = currentDegreeY + (degreeY - 17);
    Servo_X.write(currentDegreeX);
    Servo_Y.write(currentDegreeY);
    delay(1000);
    
  }
}
