#pragma once
#include "driver/gpio.h"

typedef enum{
    DOOR1 = GPIO_NUM_18,
    DOOR2 = GPIO_NUM_19
} Door;

void setup_door_sensor();
bool sensorStatus();
bool sensorStatus(Door door);

    