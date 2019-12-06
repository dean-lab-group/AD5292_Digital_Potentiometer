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
const uint16_t RDAC_enable_uncalibrated = 6150;
const uint32_t SPI_FREQ = 20000;
const unsigned long LONG_DELAY = 250;
const unsigned long SHRT_DELAY = 1;

void setup() {
  pinMode(SYNC_PIN, OUTPUT);
  pinMode(dataReadyPin, INPUT);
  SPI.begin();
  SPI.beginTransaction(SPISettings(SPI_FREQ, MSBFIRST, SPI_MODE2));
  delay(LONG_DELAY);

  digitalWrite(dataReadyPin, HIGH);
  digitalWrite(SYNC_PIN, LOW);
  sendUint16(RDAC_enable_uncalibrated);
  digitalWrite(dataReadyPin, HIGH);
  digitalWrite(SYNC_PIN, LOW);

  delay(LONG_DELAY);
}

void sendUint16(uint16_t value){
  digitalWrite(dataReadyPin, HIGH);
  digitalWrite(SYNC_PIN, LOW);
  delay(SHRT_DELAY);
  SPI.transfer16(value);
  delay(SHRT_DELAY);
  digitalWrite(SYNC_PIN, HIGH);
  digitalWrite(dataReadyPin, LOW);
  delay(LONG_DELAY);
}

void sendUint(uint8_t value){
  digitalWrite(dataReadyPin, HIGH);
  digitalWrite(SYNC_PIN, LOW);
  delay(SHRT_DELAY);
  SPI.transfer(value);
  delay(SHRT_DELAY);
  digitalWrite(SYNC_PIN, HIGH);
  digitalWrite(dataReadyPin, LOW);
  delay(LONG_DELAY);
}

void loop_through_Rs(){
  for (int level = 1024; level < 2048; level++) {
    sendUint16(level);
    delay(SHRT_DELAY);
    }
  for (int level = 2047; level > 1023; level--) {
    sendUint16(level);
    delay(SHRT_DELAY);
  }
}

void flicker(){
  sendUint16(RDAC_enable_uncalibrated);
  delay(500);
  sendUint16(1024);
  delay(500);
  sendUint16(2047);
  delay(500);
}

void loop() {
  flicker();
}

