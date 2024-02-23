#include "./headers/mqtt_client.hpp"

#define RED_1 GPIO_NUM_25
#define GREEN_1 GPIO_NUM_33
#define BLUE_1 GPIO_NUM_32

#define RED_2 GPIO_NUM_12
#define GREEN_2 GPIO_NUM_13
#define BLUE_2 GPIO_NUM_14

void rgb_setup(){
    mqtt_subcribe("ligth/rgb");
    
    pinMode(RED_1,OUTPUT);
    pinMode(GREEN_1,OUTPUT);
    pinMode(BLUE_1,OUTPUT);

    pinMode(RED_2,OUTPUT);
    pinMode(GREEN_2,OUTPUT);
    pinMode(BLUE_2,OUTPUT);

}

void set_rgb(uint8_t  red, uint8_t  green, uint8_t  blue, uint8_t index){

    switch (index){
    case 0:
        analogWrite(RED_1, red);   
        analogWrite(GREEN_1, green);
        analogWrite(BLUE_1, blue); 
        break;
    case 1:
        analogWrite(RED_2, red);   
        analogWrite(GREEN_2, green);
        analogWrite(BLUE_2, blue); 
        break;
    default:
        break;
    }
}