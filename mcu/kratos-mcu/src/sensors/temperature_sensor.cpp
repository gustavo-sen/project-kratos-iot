#include <Arduino.h>
#include "./headers/mqtt_client.hpp"

void updateSensorTemp(const char mockVal[]){
    mqtt_publish("home/sensor/temperature", mockVal);
}