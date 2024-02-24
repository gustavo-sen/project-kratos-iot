#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <string>
#include <ArduinoJson.h>

#include "./headers/mqtt_client.hpp"

#define DHTPIN 4
#define DHTTYPE DHT11

DHT_Unified dht(DHTPIN, DHTTYPE);

void sensor_dht_setup(){
    dht.begin();
    sensor_t sensor;
    dht.temperature().getSensor(&sensor);
}

void updateSensorDHT(){
    sensors_event_t temp_event, humidity_event;
    dht.temperature().getEvent(&temp_event);
    dht.humidity().getEvent(&humidity_event);

    JsonDocument doc;
    std::string jsonString;

    if (!isnan(temp_event.temperature) && !isnan(humidity_event.temperature)) {        
        doc["temperature"] = temp_event.temperature;
        doc["relative_humidity"] = humidity_event.relative_humidity;
        serializeJson(doc, jsonString);
        mqtt_publish("home/sensor/dhtsensor", jsonString.c_str());
    }
}