#include <SPI.h>
#include "driver/gpio.h"

#define LATCH_PIN GPIO_NUM_15  // Pino ST_CP (RCLK) conectado ao pino 12 do 74HC595
#define CLOCK_PIN GPIO_NUM_14  // Pino SH_CP (SRCLK) conectado ao pino 11 do 74HC595
#define DATA_PIN GPIO_NUM_13   // Pino DS (SER) conectado ao pino 14 do 74HC595   // Pino DS (SER) conectado ao pino 14 do 74HC595

unsigned char registerData = 0b00000000;

void setupShiftRegister() {
  gpio_set_direction(LATCH_PIN, GPIO_MODE_OUTPUT);
  gpio_set_direction(CLOCK_PIN, GPIO_MODE_OUTPUT);
  gpio_set_direction(DATA_PIN, GPIO_MODE_OUTPUT);

  SPI.begin();
}

void updateRegister() {
  gpio_set_level(LATCH_PIN, 0); // Inicia a transmissão de dados
  SPI.transfer(registerData);     // Envia os dados
  gpio_set_level(LATCH_PIN, 1); // Conclui a transmissão de dados
}

void setBit(int bitIndex, bool value) {
  if (value)
    registerData |= (1 << bitIndex); // Define o bit na posição especificada para HIGH
  else
    registerData &= ~(1 << bitIndex); // Define o bit na posição especificada para LOW
}