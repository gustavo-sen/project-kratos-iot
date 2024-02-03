#include <Arduino.h>
#include <wifiSetup.hpp>
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

void setup() {
    gpio_set_direction(GPIO_NUM_2, GPIO_MODE_OUTPUT);
    wificonn();

}

void loop() {

    
}
