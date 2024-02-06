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
const char* mqtt_server = "172.18.9.95";
const char* mqtt_port = "1883";

WiFiClient espClient;
PubSubClient client(espClient);

void mqtt_setup(){
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);

    if(!client.connected()){
        mqttConnect();
    }
    client.subscribe("home/luz");
    client.publish("join", "connection estabilished.");
}

void callback(char* topic, byte* message, unsigned int length) {
    std::cout << "passou callback";
    std::cout << ("Message arrived on topic: ");
    std::cout << (topic);
    std::cout << (". Message: ");
    std::string messageTemp;

    for (int i = 0; i < length; i++) {
        std::cout << ((char)message[i]);
        messageTemp += (char)message[i];
    }
    std::cout << messageTemp;
    
    // if(String(topic).equals(String(MAIN_TOPIC) + "luz")){
    //     std::string msg = messageTemp;

    //     if(messageTemp == "true"){
            
    //     }
        
    // }


//   if (String(topic) == "sw") {
//     std::cout <<("Changing output to ");
//     if(messageTemp == "on"){
//       std::cout << ("on");
//     }
//     else if(messageTemp == "off"){
//       std::cout << ("off");
//     }
//   }
}

void mqtt_publish(const char* topic, const char* payload){
    client.publish(topic, payload);
}

void mqtt_subcribe(const char* topic){
    std::string fullTopic = std::string(MAIN_TOPIC) + topic;
    client.subscribe(fullTopic.c_str());
}

// void subscribeToMQTTTopics() {
//   for (int i = 0; i < sizeof(topicos) / sizeof(topicos[0]); i++) {
//     client.subscribe(topicos[i]);
//     Serial.println("Inscrito no tópico: " + String(topicos[i]));
//   }
// }

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
