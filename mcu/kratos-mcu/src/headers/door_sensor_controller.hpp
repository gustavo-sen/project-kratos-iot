#pragma once
#include "driver/gpio.h"
#include <string>

struct DoorStruct{
    bool lastStatus;
    gpio_num_t gpio;
    std::string name;
};

extern DoorStruct doorSensor1; // Declare as extern
extern DoorStruct doorSensor2; // Declare as extern

void setup_door_sensor();
bool sensorStatus(DoorStruct door);

