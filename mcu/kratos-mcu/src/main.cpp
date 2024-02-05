#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#include "headers/wifi_setup.hpp"
#include "headers/fan_controllerl.hpp"
#include "headers/mqtt_client.hpp"

void setup() {
    gpio_set_direction(GPIO_NUM_2, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_NUM_26, GPIO_MODE_OUTPUT);

    wifiConn();
    std::string topicName = "arr";
    topicSubscribe("test");
    topicSubscribe("arr");

}

void loop() {


}
