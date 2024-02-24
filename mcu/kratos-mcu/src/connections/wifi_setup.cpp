#include "./headers/wifi_setup.hpp"
#include <WiFi.h>

//char ssid[] = "VORTEX";
//char password[] = "pprKN@Fv";
char ssid[] = "Home";
char password[] = "ioyjq89652";

void wifiSetup(){
    gpio_set_direction(GPIO_NUM_2, GPIO_MODE_OUTPUT);
    wifiConnect();
}

void wifiConnect(){
    WiFi.disconnect();
    WiFi.begin(ssid,password);
    
    while (!WiFi.isConnected()){
        gpio_set_level(GPIO_NUM_2, 1);
        vTaskDelay(100 / portTICK_RATE_MS);
        gpio_set_level(GPIO_NUM_2, 0);
        vTaskDelay(100 / portTICK_RATE_MS);
    }
    
}
