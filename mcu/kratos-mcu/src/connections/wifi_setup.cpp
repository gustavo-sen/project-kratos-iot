#include <WiFi.h>
#include <SPI.h>
#include <PubSubClient.h>

//WiFi
const char ssid[] = "Home";
const char password[] = "ioyjq89652";

//MQTT 
const char *mqtt_broker = "10.0.0.187";
const char *topic = "mcu/esp32";
const char *mqtt_username = "admin";
const char *mqtt_password = "admin";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

void wifiConn(){

    Serial.begin(9600);

    do{
        WiFi.begin(ssid,password);
       
        Serial.printf("Connecting to %s \n", ssid);
       
        gpio_set_level(GPIO_NUM_15, 1);
        vTaskDelay(1000 / portTICK_RATE_MS);
        gpio_set_level(GPIO_NUM_15, 0);
        vTaskDelay(1000 / portTICK_RATE_MS);

    } while (!WiFi.isConnected());
    
    Serial.printf("\nConnected to WiFi: \"%s\"\n", ssid);
    Serial.print("MAC Address: ");
    Serial.println(WiFi.macAddress());
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

}
