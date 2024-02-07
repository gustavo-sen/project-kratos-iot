#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include <string>
#include <ArduinoJson.h>

#include "./headers/lamp_controller.hpp"
#include "./headers/mqtt_client.hpp"

const gpio_num_t lampsPort[] = {GPIO_NUM_18, GPIO_NUM_19, GPIO_NUM_21};

void setup_lamp(){
    mqtt_subcribe("lamp");

    for (gpio_num_t pin : lampsPort) {
        gpio_set_direction(pin, GPIO_MODE_OUTPUT);
    }
}

void lamp_update(std::string& packetStr, const char& lampNum){ 

    StaticJsonDocument<200> doc;
    DeserializationError error = deserializeJson(doc, packetStr);

    if (error) {
        return;
    }

    int lampNumber = doc["lampNumber"];
    bool isOn = doc["isOn"];

    if(isOn){
        gpio_set_level(lampsPort[lampNumber], 0);
    }else{
        gpio_set_level(lampsPort[lampNumber], 1);
    }    
}
