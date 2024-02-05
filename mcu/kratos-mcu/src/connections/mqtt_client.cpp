#include <string>
#include <stdio.h>
#include <iostream>
#include <WiFi.h>
#include <PubSubClient.h>
#include "./headers/mqtt_client.hpp"

//MQTT

const char* MAIN_TOPIC = "esp32/";
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

}

void callback(char* topic, byte* message, unsigned int length) {
   Serial.print("Message arrived on topic: ");
   Serial.print(topic);
   Serial.print(". Message: ");
   String messageTemp;
  
   for (int i = 0; i < length; i++) {
     Serial.print((char)message[i]);
     messageTemp += (char)message[i];
   }

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

void mqttConnect() {

    while (!client.connected()){
        std::cout << ("Attempting MQTT connection...\n");

        if (client.connect(CLIENT_ID, MQTT_USER, MQTT_PASS)) {
            std::cout << ("connected\n");
            client.publish("connect","Im here babyyy !!");
        } else {
            std::cout << ("Connection failed") << std::endl;
            vTaskDelay(2000 / portTICK_RATE_MS);
        }
    }
    
}
