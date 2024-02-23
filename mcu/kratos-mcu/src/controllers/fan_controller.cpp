#include <Arduino.h>
#include "./headers/mqtt_client.hpp"

#define FAN_PIN GPIO_NUM_32

void fan_setup(){
    mqtt_subcribe("cooling");
    pinMode(FAN_PIN,OUTPUT);
}

void fan_speed(int speed){
    analogWrite(FAN_PIN, speed);   
}
