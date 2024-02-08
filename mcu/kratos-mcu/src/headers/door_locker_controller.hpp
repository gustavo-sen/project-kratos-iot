#pragma once
#include "driver/gpio.h"

typedef enum {
    LOCK1 = GPIO_NUM_27,
    LOCK2 = GPIO_NUM_14
} DoorLocket;

void set_up_lockers();
void set_door_lock(DoorLocket door, bool isToSet);