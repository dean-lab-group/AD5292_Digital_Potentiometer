/*
  Digital Pot Control

  A - connect this to voltage
  W - this is the pot's wiper, which changes when you set it
  B - connect this to ground.

 The circuit:
  * A pin connected to +5V
  * B pin connected to ground
  * An LED and a 220-ohm resisor in series connected from each W pin to ground
  * CS - to digital pin 10  (SS pin)
  * SDI - to digital pin 11 (MOSI pin)
  * CLK - to digital pin 13 (SCK pin)
*/

// inslude the SPI library:
#include <SPI.h>

// set pin 10 as the slave select for the digital pot:
const int SYNC_PIN = 10;
#define chipSelectPin SYNC_PIN
const int dataReadyPin = 6;
const int CMD_01 = 2048;  // 000010XXXXXXXXXX = 2048

void setup() {
  pinMode(SYNC_PIN, OUTPUT);
  pinMode(dataReadyPin, INPUT);
  Serial.begin(115200);
  SPI.begin();
  SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE2));
  delay(50);
}

void digitalPotWrite(int value) {
  unsigned char cmd = (unsigned char)(value>>8);
  unsigned char val = value & 0xff;
  Serial.println("Value\t" + String(value,BIN) + '\t' + value);
  Serial.println("Concat\t" + String(cmd,DEC) + '+' + String(val,DEC));
  //Serial.println("CMD\t" + String(cmd,BIN) + '\t' + cmd);
  //Serial.println("VAL\t" + String(val,BIN) + '\t' + val);

  digitalWrite(dataReadyPin, HIGH);
  digitalWrite(SYNC_PIN, LOW);
  delay(50);
  SPI.transfer(cmd);
  SPI.transfer(val);
  delay(50);
  
  // take the SS pin high to de-select the chip:
  digitalWrite(SYNC_PIN, HIGH);
  digitalWrite(dataReadyPin, LOW);
  
  }


void loop() {
    
    for (int level = 1024; level < 2048; level++) {
      digitalPotWrite(level);
      delay(50);
 }
     for (int level = 2047; level > 1023; level--) {
      digitalPotWrite(level);
      delay(50);
 }
}
