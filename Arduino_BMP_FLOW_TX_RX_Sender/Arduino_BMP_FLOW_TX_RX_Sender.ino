#include <SoftwareSerial.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11 
#define BMP_CS 10
Adafruit_BMP280 bme;

SoftwareSerial mySerial(10, 11);

byte statusLed    = 13;
byte sensorInterrupt = 0;
byte sensorPin       = 2;
float calibrationFactor = 4.5;
volatile byte pulseCount;  
float flowRate;
unsigned int flowMilliLitres;
unsigned long totalMilliLitres;
unsigned long oldTime;
String fml = "";
  
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  while(!bme.begin(0x76)){};
  delay(1000);
  pinMode(sensorPin, INPUT);
  digitalWrite(sensorPin, HIGH);
  pulseCount        = 0;
  flowRate          = 0.0;
  flowMilliLitres   = 0;
  oldTime           = 0;
  attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
}
  
void loop() {
    delay(100);

    if((millis() - oldTime) > 1000)
  { 
    detachInterrupt(sensorInterrupt);
    flowRate = ((1000.0 / (millis() - oldTime)) * pulseCount) / calibrationFactor;
    flowMilliLitres = (flowRate / 60) * 1000;
    fml = (String)flowMilliLitres + "";
    oldTime = millis();
    unsigned int frac;
    Serial.println((String)flowMilliLitres); 
    pulseCount = 0;
    attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
  }
   String s = "Z" + (String)bme.readPressure() + fml;
   Serial.println(s);
    char buf[14];
    s.toCharArray(buf, 15);
    mySerial.write(buf);
    Serial.println(buf);
    buf[0] = 0;
    
}
void pulseCounter(){pulseCount++;}
