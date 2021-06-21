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
  
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  if (!bme.begin(0x76)) {  
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1);
  }
}
  
void loop() {
    delay(100);
   String s = "Z" + (String)bme.readPressure();
    char buf[9];
    s.toCharArray(buf, 10);
    if(mySerial.write(buf) == 9)
    Serial.println(buf);
    buf[0] = 0;
    
}
