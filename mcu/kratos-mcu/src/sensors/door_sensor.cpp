#include "driver/gpio.h"
#include <string>

#include "./headers/mqtt_client.hpp"
#include "./headers/door_sensor.hpp"

DoorStruct doorSensor1;
DoorStruct doorSensor2;

void setup_door_sensor(){
    doorSensor1.gpio = GPIO_NUM_34;
    doorSensor1.name = "porta_1";

    doorSensor2.gpio = GPIO_NUM_35;
    doorSensor2.name = "porta_2";

    gpio_set_direction(doorSensor1.gpio, GPIO_MODE_INPUT);
    gpio_set_direction(doorSensor2.gpio, GPIO_MODE_INPUT);

    doorSensor1.lastStatus = gpio_get_level(doorSensor1.gpio);
    doorSensor2.lastStatus = gpio_get_level(doorSensor2.gpio);
}

void update_door_sensor(){
    doorSensorStatus(&doorSensor1);
    doorSensorStatus(&doorSensor2);
}

void doorSensorStatus(DoorStruct *door){
    bool status = !gpio_get_level(door->gpio);
    
    if(status != door->lastStatus){
        std::string message = (status ? "true" : "false");
        std::string topic = "home/sensor/door/" + door->name;
        
        mqtt_publish(topic.c_str(), message.c_str());
        door->lastStatus = status;
    }
}



    