#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "headers/wifi_setup.hpp"
#include "./headers/door_sensor.hpp"
#include "headers/door_locker_controller.hpp"  
#include "headers/mqtt_client.hpp"
#include "headers/lamp_controller.hpp"
#include "headers/fan_controller.hpp"
#include "headers/rgb_controller.hpp"
#include "headers/dht_sensor.hpp"
#include "headers/shift_register_controller.hpp"

void doorSensorTask(void *pvParameters);
void task3(void *pvParameters);

void setup() {
    wifiSetup();
    mqtt_setup();  

    setup_lamp();  
    setup_door_sensor();
    set_up_lockers();
    fan_setup();
    rgb_setup();
    sensor_dht_setup();
    setupShiftRegister();

    xTaskCreatePinnedToCore(doorSensorTask, "Door Sensor", 2048, NULL, 1, NULL, 1);
    xTaskCreatePinnedToCore(task3, "Task3", 8000, NULL, 2, NULL, 1);
}

void loop() {
    mqtt_client_callback_task();
}

void doorSensorTask(void *pvParameters) {
    while (true) {
        doorSensorStatus(doorSensor1);
        doorSensorStatus(doorSensor2);
        vTaskDelay(pdMS_TO_TICKS(4000));
    }
}

void task3(void *pvParameters){
    while (true){
        updateSensorDHT();
        vTaskDelay(pdMS_TO_TICKS(6000));
    }
}
