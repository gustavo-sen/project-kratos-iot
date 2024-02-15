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
    
    }else if(strcmp(topic, "home/security/door/lock") == 0){
        update_door_lock(packageTemp);

    }else if(strcmp(topic, "home/ligth/rgb/suite") == 0){
        ArduinoJson::V703PB2::StaticJsonDocument<200> jsonDoc;
        DeserializationError error = deserializeJson(jsonDoc, packageTemp);

        uint8_t red = jsonDoc["r"];
        uint8_t green = jsonDoc["g"];
        uint8_t blue = jsonDoc["b"];

        set_rgb(red, green, blue);
    
    }else if(strcmp(topic, "home/ligth/rgb/sala") == 0){
        ArduinoJson::V703PB2::StaticJsonDocument<200> jsonDoc;
        DeserializationError error = deserializeJson(jsonDoc, packageTemp);

        uint8_t red = jsonDoc["r"];
        uint8_t green = jsonDoc["g"];
        uint8_t blue = jsonDoc["b"];

        //set_rgb(red, green, blue);
    
    }else if(strcmp(topic, "home/ligth/rgb/sala") == 0){
        ArduinoJson::V703PB2::StaticJsonDocument<200> jsonDoc;
        DeserializationError error = deserializeJson(jsonDoc, packageTemp);

        uint8_t red = jsonDoc["r"];
        uint8_t green = jsonDoc["g"];
        uint8_t blue = jsonDoc["b"];

        //set_rgb(red, green, blue);
        
    }

}