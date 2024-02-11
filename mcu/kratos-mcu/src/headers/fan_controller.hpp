#pragma once
#include <Arduino.h>
#include "driver/gpio.h"

void fan_setup();
void fan_speed(int speed);