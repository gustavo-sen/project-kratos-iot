#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include <iostream>

#include "headers/wifi_setup.hpp"
#include "headers/door_sensor_controller.hpp"
#include "headers/door_locker_controller.hpp"  
#include "headers/mqtt_client.hpp"
#include "headers/lamp_controller.hpp"

void setup() {
    wifiSetup();
    mqtt_setup();  

    setup_lamp();  
    setup_door_sensor();
    set_up_lockers();

}

void loop() {
    mqtt_client_callback_task();
}



