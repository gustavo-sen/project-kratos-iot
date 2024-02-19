#include <Arduino.h>
#include "driver/gpio.h"
#include "headers/shift_register_controller.hpp"

#define LATCH_PIN 5  // Pino ST_CP (RCLK) conectado ao pino 12 do 74HC595
#define CLOCK_PIN 18  // Pino SH_CP (SRCLK) conectado ao pino 11 do 74HC595
#define DATA_PIN 23   // Pino DS (SER) conectado ao pino 14 do 74HC595 

u_int8_t register_o = 0;

void setupShiftRegister() {
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
  digitalWrite(LATCH_PIN, HIGH);
}

void setBit(REG_XOS bitIndex, bool value) {
  for(u_int8_t i = 0; i < 8; i++){
      value ? register_o |= (1 << bitIndex) : register_o &= ~(1 << bitIndex);
  }
  updateShiftRegister();
}

void updateShiftRegister(){
  //todo
}

