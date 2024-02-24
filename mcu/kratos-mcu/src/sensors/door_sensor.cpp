#include "driver/gpio.h"
#include <string>

#include "./headers/mqtt_client.hpp"
#include "./headers/door_sensor.hpp"

DoorStruct doorSensor1;
DoorStruct doorSensor2;

void setup_door_sensor(){
    doorSensor1.lastStatus = true;
    doorSensor1.gpio = 34;
    doorSensor1.name = "porta_1";

    doorSensor2.lastStatus = true;
    doorSensor2.gpio = 35;
    doorSensor2.name = "porta_2";

    pinMode(doorSensor1.gpio, INPUT_PULLUP);
    pinMode(doorSensor2.gpio, INPUT_PULLUP);

}

void update_door_sensor(){
    doorSensorStatus(&doorSensor1);
    doorSensorStatus(&doorSensor2);
}

void doorSensorStatus(DoorStruct *door){
    bool status = !digitalRead(door->gpio);
    
    if(status != door->lastStatus){
        std::string opc = (status ? "open" : "closed");
        std::string message = "Door " + door->name + " is now " + opc;
        std::string topic = "home/sensor/door/" + door->name;
        
        mqtt_publish(topic.c_str(), message.c_str());
        door->lastStatus = status;
    }
}



    