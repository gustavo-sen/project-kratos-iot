#include "driver/gpio.h"

typedef enum {
    LOCK1 = GPIO_NUM_27,
    LOCK2 = GPIO_NUM_14
} DoorLocket;

void set_up_lockers(){
    gpio_set_direction((gpio_num_t) LOCK1, GPIO_MODE_OUTPUT);
    gpio_set_direction((gpio_num_t) LOCK2, GPIO_MODE_OUTPUT);
}

void set_door_lock(DoorLocket door, bool isToSet){
    gpio_set_level((gpio_num_t) door, isToSet);
}