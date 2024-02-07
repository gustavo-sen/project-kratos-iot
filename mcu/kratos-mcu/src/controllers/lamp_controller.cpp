#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include <string>


#include "./headers/lamp_controller.hpp"
#include "./headers/mqtt_client.hpp"

void setup_lamp(){
    mqtt_subcribe("luz");
    gpio_set_direction(GPIO_NUM_21, GPIO_MODE_OUTPUT);
}

void lamp_update(std::string& package){
    if(package == "true"){
        gpio_set_level(GPIO_NUM_21, 0);
    }else{
        gpio_set_level(GPIO_NUM_21, 1);
    }
}