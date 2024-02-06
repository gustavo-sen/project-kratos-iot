#include <string>
#include <stdio.h>
#include <iostream>
#include <set>
#include <type_traits>

#include <WiFi.h>
#include <PubSubClient.h>

#include "./headers/mqtt_client.hpp"

//MQTT
const char* MAIN_TOPIC = "home/";
const char* CLIENT_ID = "esp32-client";
const char* MQTT_USER = "admin";
const char* MQTT_PASS = "admin";
const char* MQTT_SERVER = "172.18.9.95";
const char* MQTT_PORT = "1883";

WiFiClient espClient;
PubSubClient client(espClient);

void mqtt_setup(){
    client.setServer(MQTT_SERVER, 1883);
    client.setCallback(callback);

    mqttConnect();

    client.publish("join", "connection estabilished.");
}

void client_loop(){
    client.loop();
}

void callback(char* topic, byte* message, unsigned int length) {
    std::string messageTemp;

    for (int i = 0; i < length; i++) {
        messageTemp += (char)message[i];
    }
    std::cout << messageTemp << std::endl;

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
    strcat(topicoCompleto, topic
    );
    
    // Assumindo que client.subscribe() aceita uma const char*
    client.subscribe(topicoCompleto);
    
    // Imprime a mensagem
    std::cout << "Topico: " << topicoCompleto << " inscrito" << std::endl;
    
    // Libera a memória alocada
    delete[] topicoCompleto;
}

void mqttConnect() {

    while (!client.connected()){
        std::cout << ("Attempting MQTT connection...\n");

        if (client.connect(CLIENT_ID, MQTT_USER, MQTT_PASS)) {
            std::cout << ("connected\n");
        } else {
            std::cout << ("Connection failed") << std::endl;
            vTaskDelay(2000 / portTICK_RATE_MS);
        }
    }
    
}
