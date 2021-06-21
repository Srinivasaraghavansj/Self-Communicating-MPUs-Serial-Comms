#include<Servo.h>
const int trigpin1 = 3;
const int echopin1 = 4;
const int servopin = 5;
float duration1, distance1;
Servo door;
void setup() {
pinMode(trigpin1, OUTPUT); 
pinMode(echopin1, INPUT);
Serial.begin(9600);
door.detach(); 
door.attach(servopin);
door.write(90);
delay(1000);
door.detach(); 
}

void loop() {
digitalWrite(trigpin1, LOW);
delayMicroseconds(2);
digitalWrite(trigpin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin1, LOW);
duration1 = pulseIn(echopin1, HIGH);
distance1= duration1*0.034/2;
Serial.println((String)distance1);
delay(50);
if(distance1 > 15){
  door.attach(servopin);
  door.write(150);
  delay(1000);
  door.detach();
}
else
{
  door.attach(servopin);
  door.write(90);
  delay(50);
  door.detach();
}
}
