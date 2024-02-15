#pragma once
#include "driver/gpio.h"
#include <string>

struct DoorStruct{
    bool lastStatus;
    gpio_num_t gpio;
    std::string name;
};

extern DoorStruct doorSensor1;
extern DoorStruct doorSensor2; 

void setup_door_sensor();
void doorSensorStatus(DoorStruct door);

