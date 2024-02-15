#pragma once
#include "driver/gpio.h"

struct DoorStruct{
    bool lastStatus;
    gpio_num_t gpio;
} ;

void setup_door_sensor();
bool sensorStatus(DoorStruct door);

