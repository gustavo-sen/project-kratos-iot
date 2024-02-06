#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include <esp_task_wdt.h>

#include "headers/wifi_setup.hpp"
#include "headers/fan_controllerl.hpp"
#include "headers/mqtt_client.hpp"

const int watchdogTimeout = 5;

void task_mqtt_callback(void *xTaskParameters);

void setup() {
    esp_task_wdt_init(watchdogTimeout, true); 
    esp_task_wdt_add(NULL);

    wifiSetup();
    mqtt_setup();

    mqtt_subcribe("luz");
    
    //tasks
    xTaskCreate(task_mqtt_callback, "Task_mqtt_callback", 10000, NULL, 1, NULL);

}

void loop() {
    esp_task_wdt_reset();
}

void task_mqtt_callback(void *xTaskParameters){
    while(1){
        mqttConnect();
        client_loop();
    }
}