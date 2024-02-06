#include "./headers/wifi_setup.hpp"

#include <WiFi.h>
#include <SPI.h>
#include <PubSubClient.h>

//WiFi
char ssid[] = "VORTEX";
char password[] = "pprKN@Fv";

void wifiSetup(){
    gpio_set_direction(GPIO_NUM_2, GPIO_MODE_OUTPUT);

    wifiConnect();
}

void wifiConnect(){

    Serial.begin(9600);

    do{
        WiFi.begin(ssid,password);
       
        Serial.printf("Connecting to %s \n", ssid);
       
        gpio_set_level(GPIO_NUM_2, 1);
        vTaskDelay(100 / portTICK_RATE_MS);
        gpio_set_level(GPIO_NUM_2, 0);
        vTaskDelay(100 / portTICK_RATE_MS);

    } while (!WiFi.isConnected());
    
}
