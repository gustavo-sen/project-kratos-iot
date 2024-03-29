#pragma once
#include <Arduino.h>

void mqtt_setup();
void callback(char* topic, byte* message, unsigned int length);
void mqtt_publish(const char* topic, const char* payload);
void mqtt_subcribe(const char* topic); 
void mqttConnect();
void mqtt_client_callback_task();