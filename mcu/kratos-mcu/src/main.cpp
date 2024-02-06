#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include <esp_task_wdt.h>

#include "headers/wifi_setup.hpp"
#include "headers/fan_controllerl.hpp"
#include "headers/mqtt_client.hpp"

const int watchdogTimeout = 5;

void setup() {
    esp_task_wdt_init(watchdogTimeout, true); 
    esp_task_wdt_add(NULL);

    wifiSetup();
    mqtt_setup();
    
}

void loop() {
    esp_task_wdt_reset();

}
