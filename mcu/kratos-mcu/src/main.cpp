#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include <iostream>

#include "headers/wifi_setup.hpp"
#include "headers/fan_controllerl.hpp"
#include "headers/mqtt_client.hpp"
#include "headers/lamp_controller.hpp"

void setup() {
    wifiSetup();
    mqtt_setup();  

    setup_lamp();  
}

void loop() {
    mqtt_client_callback_task();
}



