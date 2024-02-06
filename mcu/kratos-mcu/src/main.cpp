#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include <esp_task_wdt.h>

#include "headers/wifi_setup.hpp"
#include "headers/fan_controllerl.hpp"
#include "headers/mqtt_client.hpp"
#include "headers/lamp_controller.hpp"

const int watchdogTimeout = 5;

void task_mqtt_callback(void *xTaskParameters);

void setup() {

    wifiSetup();
    mqtt_setup();

    setup_lamp();

    //tasks
    xTaskCreate(task_mqtt_callback, "Task_mqtt_callback", 10000, NULL, 1, NULL);

}

void loop() {
}

void task_mqtt_callback(void *xTaskParameters){
    while(1){
        mqttConnect();
        client_loop();
    }
}

