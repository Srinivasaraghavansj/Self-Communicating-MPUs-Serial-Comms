#include "SoftwareSerial.h"
bool b = true;
SoftwareSerial ard1(10,11);

void setup() {
  // put your setup code here, to run once:
ard1.begin(9600);
Serial.begin(9600);
pinMode(13,OUTPUT)
}

void loop() {
  // put your main code here, to run repeatedly:
ard1.write("Working ya");
if(b == true)

delay(100);

}
