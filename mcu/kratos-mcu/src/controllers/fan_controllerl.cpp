#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define FAN_PIN GPIO_NUM_17

void fanSetup(){
    gpio_set_direction(FAN_PIN, GPIO_MODE_OUTPUT);
}

void fanSpeed(float& speedPercentage){

    if(!speedPercentage > 1 && speedPercentage >= 0){
        
        gpio_set_level(FAN_PIN, 1);        
        //TODO
    }

}