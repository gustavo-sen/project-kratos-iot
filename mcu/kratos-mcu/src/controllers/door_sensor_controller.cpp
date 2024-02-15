#include "driver/gpio.h"
#include "./headers/mqtt_client.hpp"
#include <string>

struct DoorStruct{
    bool lastStatus;
    gpio_num_t gpio;
} ;

void setup_door_sensor(){

    DoorStruct door1, door2;
    
    door1.lastStatus = true;
    door1.gpio = GPIO_NUM_12;

    door2.gpio = GPIO_NUM_13;
    door2.lastStatus = true;

    gpio_set_direction(door1.gpio, GPIO_MODE_INPUT);
    gpio_set_direction(door2.gpio, GPIO_MODE_INPUT);
}

bool sensorStatus(DoorStruct door){
    bool status = !gpio_get_level((gpio_num_t) door.gpio);
    
    //TODO CONFERIR LÓGICA LAST STATUS 
    std::string opc = (door.lastStatus ? "open" : "closed");
    std::string message = "Door INVALID was " + opc;

    mqtt_publish("home/sensor/door/porta1", message.c_str());
    
    return status;
}



    