#include <WiFi.h>
#include <SPI.h>

const char ssid[] = "Home";
const char password[] = "ioyjq89652";

void wificonn(){

    Serial.begin(9600);

    do{
        WiFi.begin(ssid,password);
       
        Serial.printf("Connecting to %s \n", ssid);
       
        gpio_set_level(GPIO_NUM_2, 1);
        vTaskDelay(1000 / portTICK_RATE_MS);
        gpio_set_level(GPIO_NUM_2, 0);
        vTaskDelay(1000 / portTICK_RATE_MS);

    } while (!WiFi.isConnected());
    
    Serial.printf("\nConnected to WiFi: \"%s\"\n", ssid);
    Serial.print("MAC Address: ");
    Serial.println(WiFi.macAddress());
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

}