#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "PubSubClient.h"

#include "headers/wifi_setup.hpp"
#include "headers/fan_controllerl.hpp"
#include "headers/mqtt_client.hpp"

void setup() {
    Serial.begin(9600);
    gpio_set_direction(GPIO_NUM_26, GPIO_MODE_OUTPUT);
    wifiSetup();
    wifiConnect();
    mqtt_setup();
}

void loop() {

    mqtt_publish("sw","sou burro");

    vTaskDelay(3000 / portTICK_RATE_MS);
}
