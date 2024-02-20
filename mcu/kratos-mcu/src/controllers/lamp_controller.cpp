#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include <string>
#include <ArduinoJson.h>

#include "./headers/lamp_controller.hpp"
#include "./headers/mqtt_client.hpp"
#include "./headers/shift_register_controller.hpp"

const REG_XOS lampsPort[] = {REG_XO_1,REG_XO_2,REG_XO_3,REG_XO_4,REG_XO_5,REG_XO_6};

void setup_lamp(){
    mqtt_subcribe("lamp");
}

void lamp_update(std::string& packetStr, const char& lampNum){ 

    JsonDocument doc;
    DeserializationError error = deserializeJson(doc, packetStr);

    if (error) {
        return;
    }

    int lampNumber = doc["lampNumber"];
    bool isOn = doc["isOn"];
    std::string lampName = doc["name"];

    if(isOn){
        setBit(lampsPort[lampNumber], true);
    }else{
        setBit(lampsPort[lampNumber], false);
    }    

    std::string message = "Lamp " + lampName + " was turned " + (isOn ? "on" : "off");

    mqtt_publish("status", message.c_str());
}
