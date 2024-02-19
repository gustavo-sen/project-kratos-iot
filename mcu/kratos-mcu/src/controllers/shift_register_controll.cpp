#include <Arduino.h>
#include "driver/gpio.h"

#define LATCH_PIN 5  // Pino ST_CP (RCLK) conectado ao pino 12 do 74HC595
#define CLOCK_PIN 18  // Pino SH_CP (SRCLK) conectado ao pino 11 do 74HC595
#define DATA_PIN 23   // Pino DS (SER) conectado ao pino 14 do 74HC595 

typedef enum{
  X1, X2, X3,
  X4, X5, X6,
  X7, X8
} shiftDoor;

void setupShiftRegister() {
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
  digitalWrite(LATCH_PIN, HIGH);
}

void setBit(shiftDoor bitIndex, bool value) {
  byte bitsToSend = 0;

  // turn off the output so the pins don't light up

  // while you're shifting bits:

  digitalWrite(LATCH_PIN, LOW);

  // turn on the next highest bit in bitsToSend:

  bitWrite(bitsToSend, bitIndex, value);

  // shift the bits out:

  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, bitsToSend);

  // turn on the output so the LEDs can light up:

  digitalWrite(DATA_PIN, HIGH);
}

