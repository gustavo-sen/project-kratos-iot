#include "driver/gpio.h"
#include <ArduinoJson.h>
#include "./headers/mqtt_client.hpp"
#include "./headers/shift_register_controller.hpp"

const REG_XOS lockers[] = {REG_XO_6, REG_XO_7};

void set_up_lockers(){
    mqtt_subcribe("security/trancas");
}

void update_door_lock(std::string& packetStr){
    StaticJsonDocument<200> doc;
    DeserializationError error = deserializeJson(doc, packetStr);

    int lockNumber = doc["lockNumber"];
    std::string lockName = doc["lockName"];
    bool isLock = doc["isLock"];


    std::string message = "Lock " + lockName + " was " + (isLock ? "closed" : "open");

    mqtt_publish("status", message.c_str());
}