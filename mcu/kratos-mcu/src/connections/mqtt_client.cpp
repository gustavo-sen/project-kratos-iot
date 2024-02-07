#include <string.h>
#include <stdio.h>
#include <iostream>
#include <set>
#include <type_traits>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <WiFi.h>
#include <PubSubClient.h>

#include "./headers/mqtt_client.hpp"
#include "./headers/lamp_controller.hpp"

//MQTT
const char* MAIN_TOPIC = "home/";
const char* CLIENT_ID = "esp32-client";
const char* MQTT_USER = "admin";
const char* MQTT_PASS = "admin";
const char* MQTT_SERVER = "172.18.9.95";
const char* MQTT_PORT = "1883";

WiFiClient espClient;
PubSubClient client(espClient);

void mqtt_client_callback_task(void* xTaskParameters);

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

    lamp_update(packageTemp);

}

void mqtt_client_callback_task(){
    while (1) {
        if (!client.connected()) {
            mqttConnect();
        } else {
            client.loop();
        }
    }
}

void mqtt_publish(const char* topic, const char* payload){
    client.publish(topic, payload);
}

void mqtt_subcribe(const char* topic){
    // Aloca memória suficiente para armazenar o tópico completo
    char* topicoCompleto = new char[strlen(MAIN_TOPIC) + strlen(topic) + 1];
    
    // Copia MAIN_TOPIC para topicoCompleto
    strcpy(topicoCompleto, MAIN_TOPIC);
    
    // Concatena topico em topicoCompleto
    strcat(topicoCompleto, topic);
    
    client.subscribe(topicoCompleto);
    
    std::cout << "inscrito em " << topicoCompleto;
    
    // Libera a memória alocada
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
