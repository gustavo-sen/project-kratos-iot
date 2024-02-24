#include <ArduinoJson.h>
#include "./headers/mqtt_client.hpp"
#include "./headers/shift_register_controller.hpp"

const REG_XOS lockers[2] = {REG_XO_6, REG_XO_7};

void set_up_lockers(){
    mqtt_subcribe("security/lockers");
}

void update_door_lock(std::string& packetStr){
    JsonDocument doc;
    deserializeJson(doc, packetStr);

    uint8_t lockNumber = doc["lockNumber"];
    std::string lockName = doc["lockName"];
    bool isLock = doc["isLock"];

    switch (lockNumber){
        case 0:
            setBit(REG_XO_6, isLock);
            break;
        case 1:
            setBit(REG_XO_7, isLock);
            break;
        default:
            break;
    }

    std::string message = "Lock " + lockName + " was " + (isLock ? "closed" : "open");

    mqtt_publish("status", message.c_str());
}