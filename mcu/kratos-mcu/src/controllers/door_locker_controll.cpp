#include "driver/gpio.h"
#include <ArduinoJson.h>
#include "./headers/mqtt_client.hpp"

void set_up_lockers(){
    //gpio_set_direction((gpio_num_t) LOCK1, GPIO_MODE_OUTPUT);
    // gpio_set_direction((gpio_num_t) LOCK2, GPIO_MODE_OUTPUT);
}

void update_door_lock(std::string& packetStr){
    StaticJsonDocument<200> doc;
    DeserializationError error = deserializeJson(doc, packetStr);

    int lockNumber = doc["lockNumber"];
    std::string lockName = doc["lockName"];
    bool isLock = doc["isLock"];

    //todo
     //set_door_lock(LOCK1, true);

    std::string message = "Lock " + lockName + " was " + (isLock ? "closed" : "open");

    mqtt_publish("status", message.c_str());
}