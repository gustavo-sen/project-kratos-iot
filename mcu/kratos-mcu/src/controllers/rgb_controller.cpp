#include "./headers/mqtt_client.hpp"

typedef enum{

} LED;

void rgb_setup(){
    mqtt_subcribe("ligth/rgb");
    pinMode(GPIO_NUM_25,OUTPUT);
    pinMode(GPIO_NUM_33,OUTPUT);
    pinMode(GPIO_NUM_32,OUTPUT);
}

void set_rgb(uint8_t  red, uint8_t  green, uint8_t  blue){
    analogWrite(GPIO_NUM_25, red);   
    analogWrite(GPIO_NUM_33, green);
    analogWrite(GPIO_NUM_32, blue);   
}