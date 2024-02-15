#include "driver/gpio.h"
#include "./headers/mqtt_client.hpp"
#include <string>
#include "./headers/door_sensor_controller.hpp"

DoorStruct doorSensor1;
DoorStruct doorSensor2;

void setup_door_sensor(){
    doorSensor1.lastStatus = true;
    doorSensor1.gpio = GPIO_NUM_34;
    doorSensor1.name = "porta_1";

    doorSensor2.gpio = GPIO_NUM_35;
    doorSensor2.lastStatus = true;
    doorSensor2.name = "porta_2";

    gpio_set_direction(doorSensor1.gpio, GPIO_MODE_INPUT);
    gpio_set_direction(doorSensor2.gpio, GPIO_MODE_INPUT);
}

bool sensorStatus(DoorStruct door){
    bool status = !gpio_get_level((gpio_num_t) door.gpio);

    if(true){
        std::string opc = (status ? "open" : "closed");
        std::string message = "Door " + door.name + " was " + opc;
        std::string topic = "home/sensor/door/" + door.name;
        
        mqtt_publish(topic.c_str(), message.c_str());
    }

    door.lastStatus = status;

    return status;
}



    