#pragma once

void mqtt_setup();
void callback(char* topic, byte* message, unsigned int length);
void mqtt_connect();
PubSubClient getClient();