#pragma once

void mqtt_setup();
void callback(char* topic, byte* message, unsigned int length);
void mqtt_connect();
void mqtt_publish(const char* topic, const char* payload);