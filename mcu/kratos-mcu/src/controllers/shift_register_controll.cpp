#include <Arduino.h>
#include "driver/gpio.h"

#define LATCH_PIN 5  // Pino ST_CP (RCLK) conectado ao pino 12 do 74HC595
#define CLOCK_PIN 18  // Pino SH_CP (SRCLK) conectado ao pino 11 do 74HC595
#define DATA_PIN 23   // Pino DS (SER) conectado ao pino 14 do 74HC595 

enum{
  X1, X2, X3,
  X4, X5, X6,
  X7, X8
};

byte registerData = 0;

void setupShiftRegister() {
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
}

void setBit(int bitIndex, bool value) {
  digitalWrite (LATCH_PIN, LOW );
  shiftOut (DATA_PIN, CLOCK_PIN, LSBFIRST, bitIndex);
  digitalWrite (LATCH_PIN, HIGH );
  delay(500);
}

