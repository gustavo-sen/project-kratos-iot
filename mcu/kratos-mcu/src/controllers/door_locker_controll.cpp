#include <ArduinoJson.h>
#include "./headers/mqtt_client.hpp"
#include "./headers/shift_register_controller.hpp"

const REG_XOS lockers[2] = {REG_XO_6, REG_XO_7};

void set_up_lockers(){
    mqtt_subcribe("security/lockers");
}

void update_door_lock(std::string& packetStr){
    JsonDocument doc;
    DeserializationError error = deserializeJson(doc, packetStr);

    int lockNumber = doc["lockNumber"];
    std::string lockName = doc["lockName"];
    bool isLock = doc["isLock"];

    if(lockNumber == 0){
        setBit(REG_XO_6, isLock);
    }else{
        setBit(REG_XO_7, isLock);
    }

    std::string message = "Lock " + lockName + " was " + (isLock ? "closed" : "open");

    mqtt_publish("status", message.c_str());
}