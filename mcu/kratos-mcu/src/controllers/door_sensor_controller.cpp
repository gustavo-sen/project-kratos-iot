#include "driver/gpio.h"

typedef enum{
    DOOR1 = GPIO_NUM_12,
    DOOR2 = GPIO_NUM_13
} Door;

void setup_door_sensor(){
    gpio_set_direction((gpio_num_t) DOOR1, GPIO_MODE_INPUT);
    gpio_set_direction((gpio_num_t) DOOR2, GPIO_MODE_INPUT);
}

bool sensorStatus(){
    return ! (gpio_get_level((gpio_num_t) DOOR1) || gpio_get_level((gpio_num_t) DOOR2));
}

bool sensorStatus(Door door){
    return ! gpio_get_level((gpio_num_t) door);
}



    