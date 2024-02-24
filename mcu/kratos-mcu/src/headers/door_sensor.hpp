#pragma once
#include "driver/gpio.h"
#include <string>

struct DoorStruct{
    bool lastStatus;
    int gpio;
    std::string name;
};

void setup_door_sensor();
void update_door_sensor();
void doorSensorStatus(DoorStruct *door);

