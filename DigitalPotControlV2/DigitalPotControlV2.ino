#include <SPI.h>

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

const int SYNC_PIN = 10;
const int dataReadyPin = 6;

#define RDACenable_uncalibrated 6150
#define chipSelectPin SYNC_PIN
#define SPI_FREQ 2000000
#define LONG_DELAY 50
#define SHRT_DELAY 10

void setup() {
  pinMode(SYNC_PIN, OUTPUT);
  pinMode(dataReadyPin, INPUT);
  Serial.begin(115200);
  SPI.begin();
  SPI.beginTransaction(SPISettings(SPI_FREQ, MSBFIRST, SPI_MODE2));
  delay(LONG_DELAY);
  sendUint16(6150);
}

void sendUint16(uint16_t value){
  digitalWrite(dataReadyPin, HIGH);
  digitalWrite(SYNC_PIN, LOW);
  delay(LONG_DELAY);
  SPI.transfer16(value);
  delay(SHRT_DELAY);
  digitalWrite(SYNC_PIN, HIGH);
  digitalWrite(dataReadyPin, LOW);
  delay(LONG_DELAY);
}

void sendUint(uint8_t value){
  digitalWrite(dataReadyPin, HIGH);
  digitalWrite(SYNC_PIN, LOW);
  delay(LONG_DELAY);
  SPI.transfer(value);
  delay(SHRT_DELAY);
  digitalWrite(SYNC_PIN, HIGH);
  digitalWrite(dataReadyPin, LOW);
  delay(LONG_DELAY);
}

void digitalPotWrite(uint16_t value) {
  //unsigned char cmd = (unsigned char)(value>>8);
  //unsigned char val = value & 0xff;
  //Serial.println("Concat\t" + String(cmd,DEC) + '+' + String(val,DEC));
  sendUint16(value);
  //sendUint(cmd);
  //sendUint(val);
}

void loop() {
  sendUint16(1024);
  delay(250);
  sendUint16(2047);
  delay(250);
//    for (int level = 1024; level < 2048; level++) {
//      Serial.println("Value\t" + String(level, BIN) + '\t' + level);
//      digitalPotWrite(level);
//      delay(50);
// }
//     for (int level = 2047; level > 1023; level--) {
//      Serial.println("Value\t" + String(level, BIN) + '\t' + level);
//      digitalPotWrite(level);
//      delay(50);
// }
}
