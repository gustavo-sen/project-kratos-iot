#include "./headers/mqtt_client.hpp"

void rgb_setup(){
    mqtt_subcribe("ligth/rgb/suite");
    mqtt_subcribe("ligth/rgb/sala");
    
    pinMode(GPIO_NUM_25,OUTPUT);
    pinMode(GPIO_NUM_32,OUTPUT);
    pinMode(GPIO_NUM_33,OUTPUT);

    pinMode(GPIO_NUM_12,OUTPUT);
    pinMode(GPIO_NUM_13,OUTPUT);
    pinMode(GPIO_NUM_14,OUTPUT);

}

void set_rgb(uint8_t  red, uint8_t  green, uint8_t  blue){
    analogWrite(GPIO_NUM_25, red);   
    analogWrite(GPIO_NUM_33, green);
    analogWrite(GPIO_NUM_32, blue);   

    analogWrite(GPIO_NUM_12, red);   
    analogWrite(GPIO_NUM_13, green);
    analogWrite(GPIO_NUM_14, blue); 
}