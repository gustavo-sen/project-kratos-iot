#include "./headers/mqtt_client.hpp"

void rgb_setup(){
    mqtt_subcribe("ligth/rgb");
    
    pinMode(GPIO_NUM_25,OUTPUT);
    pinMode(GPIO_NUM_32,OUTPUT);
    pinMode(GPIO_NUM_33,OUTPUT);

    pinMode(GPIO_NUM_12,OUTPUT);
    pinMode(GPIO_NUM_13,OUTPUT);
    pinMode(GPIO_NUM_14,OUTPUT);

}

void set_rgb(uint8_t  red, uint8_t  green, uint8_t  blue, uint8_t index){

    switch (index){
    case 0:
        analogWrite(GPIO_NUM_25, red);   
        analogWrite(GPIO_NUM_33, green);
        analogWrite(GPIO_NUM_32, blue); 
        break;
    case 1:
        analogWrite(GPIO_NUM_12, red);   
        analogWrite(GPIO_NUM_13, green);
        analogWrite(GPIO_NUM_14, blue); 
        break;
    default:
        break;
    }
}