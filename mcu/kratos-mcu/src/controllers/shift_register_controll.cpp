#include <Arduino.h>
#include "driver/gpio.h"
#include "headers/shift_register_controller.hpp"

#define LATCH_PIN GPIO_NUM_18  // Pino ST_CP (RCLK) conectado ao pino 12 do 74HC595
#define CLOCK_PIN GPIO_NUM_23  // Pino SH_CP (SRCLK) conectado ao pino 11 do 74HC595
#define DATA_PIN GPIO_NUM_5   // Pino DS (SER) conectado ao pino 14 do 74HC595 

u_int8_t register_o = 0;

void setupShiftRegister() {
  gpio_set_direction(CLOCK_PIN, GPIO_MODE_OUTPUT);
  gpio_set_direction(DATA_PIN, GPIO_MODE_OUTPUT);
  gpio_set_direction(LATCH_PIN, GPIO_MODE_OUTPUT);
  gpio_set_level(LATCH_PIN, 1);
}

void setBit(REG_XOS bitIndex, bool value) {
  for(u_int8_t i = 0; i < 8; i++){
      value ? register_o |= (1 << bitIndex) : register_o &= ~(1 << bitIndex);
  }
  updateShiftRegister();
}

void updateShiftRegister(){
  gpio_set_level(LATCH_PIN, 0);

  for(u_int8_t i = 0; i < 8; i++){
    gpio_set_level(DATA_PIN, !!(register_o & (1 << (7 - i))));
    gpio_set_level(CLOCK_PIN, 1);
    gpio_set_level(CLOCK_PIN, 0);
  }
  gpio_set_level(LATCH_PIN, 1);
}

