#include <string.h>
#include <string>
#include <type_traits>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <WiFi.h>
#include <PubSubClient.h>

#include "./headers/mqtt_client.hpp"
#include "./headers/callback_mqtt.hpp"

#include "./headers/mqtt_client.hpp"
#include "./headers/lamp_controller.hpp"
#include "./headers/fan_controller.hpp"
#include "./headers/rgb_controller.hpp"
#include "./headers/door_locker_controller.hpp"

//MQTT
const char* MAIN_TOPIC = "home/";
const char* CLIENT_ID = "esp32-client";
const char* MQTT_USER = "admin";
const char* MQTT_PASS = "admin";

const char* MQTT_SERVER = "172.18.9.95";
// const char* MQTT_SERVER = "10.0.0.221";
const char* MQTT_PORT = "1883";

WiFiClient espClient;
PubSubClient client(espClient);

void mqtt_setup(){
    client.setServer(MQTT_SERVER, 1883);
    client.setCallback(callback);
    mqttConnect();

    client.publish("join", "connection estabilished.");
}

void callback(char* topic, byte* message, unsigned int length) {
    std::string packageTemp;

    for (unsigned int i = 0; i < length; i++) {
        packageTemp += (char)message[i];
    }

    update(topic, packageTemp);

}

void mqtt_client_callback_task(){
    if (!client.connected()) {
        mqttConnect();
    } else {
        client.loop();
    }
}

void mqtt_publish(const char* topic, const char* payload){
    client.publish(topic, payload);
}

void mqtt_subcribe(const char* topic){
    char* topicoCompleto = new char[strlen(MAIN_TOPIC) + strlen(topic) + 1];
    
    strcpy(topicoCompleto, MAIN_TOPIC);
    strcat(topicoCompleto, topic);
    
    client.subscribe(topicoCompleto);
    delete[] topicoCompleto;
}

void mqttConnect() {
    while (!client.connected()){
        if (client.connect(CLIENT_ID, MQTT_USER, MQTT_PASS)) {
        } else {
            vTaskDelay(2000 / portTICK_RATE_MS);
        }
    }
}
