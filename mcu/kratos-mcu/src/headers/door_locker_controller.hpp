#pragma once

#include <string>

#include "driver/gpio.h"

void set_up_lockers();
void update_door_lock(std::string& packetStr);