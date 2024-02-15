#include <Arduino.h>

#include "./headers/mqtt_client.hpp"

void fan_setup(){
    mqtt_subcribe("cooling");
    pinMode(GPIO_NUM_27,OUTPUT);
}

void fan_speed(int speed){
    analogWrite(GPIO_NUM_27, speed);   
}
