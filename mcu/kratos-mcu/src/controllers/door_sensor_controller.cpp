#include "driver/gpio.h"
#include "./headers/mqtt_client.hpp"
#include <string>

typedef enum{
    DOOR1 = GPIO_NUM_12,
    DOOR2 = GPIO_NUM_13
} Door;

bool sensorStatus(Door door);

void setup_door_sensor(){
    gpio_set_direction((gpio_num_t) DOOR1, GPIO_MODE_INPUT);
    gpio_set_direction((gpio_num_t) DOOR2, GPIO_MODE_INPUT);
}

bool sensorStatus(){
    return ! (gpio_get_level((gpio_num_t) DOOR1) || gpio_get_level((gpio_num_t) DOOR2));
}

bool sensorStatus(Door door){
    bool status = !gpio_get_level((gpio_num_t) door);
    std::string opc = (status ? "open" : "closed");
    std::string message = "Door INVALID was " + opc;

    mqtt_publish("home/sensor/door/porta1", message.c_str());
    
    return status;
}



    