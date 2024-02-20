#include <ArduinoJson.h>
#include "./headers/mqtt_client.hpp"
#include "./headers/lamp_controller.hpp"
#include "./headers/fan_controller.hpp"
#include "./headers/rgb_controller.hpp"
#include "./headers/door_locker_controller.hpp"

void update(char* topic, std::string packageTemp){

    if(strcmp(topic, "home/lamp") == 0){
        lamp_update(packageTemp, 0);
    
    }else if(strcmp(topic, "home/cooling") == 0){
        fan_speed(std::stoi(packageTemp));
    
    }else if(strcmp(topic, "home/security/lockers") == 0){
        update_door_lock(packageTemp);

    }else if(strcmp(topic, "home/ligth/rgb") == 0){
        ArduinoJson::JsonDocument jsonDoc;
        DeserializationError error = deserializeJson(jsonDoc, packageTemp);
        if(!error){
            uint8_t index = jsonDoc["index"];
        
            JsonObject rgb = jsonDoc["rgb"];
            uint8_t red = rgb["r"];
            uint8_t green = rgb["g"];
            uint8_t blue = rgb["b"];

            set_rgb(red, green, blue, index);
        }
        
    }
}