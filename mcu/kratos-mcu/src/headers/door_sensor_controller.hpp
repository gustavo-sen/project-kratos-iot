#pragma once
#include "driver/gpio.h"

typedef enum{
    DOOR1 = GPIO_NUM_27,
    DOOR2 = GPIO_NUM_14
} Door;

void setup_door_sensor();
bool sensorStatus();
bool sensorStatus(Door door);

    