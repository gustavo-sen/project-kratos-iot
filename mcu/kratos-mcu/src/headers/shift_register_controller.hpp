#pragma once

typedef enum{
  X1, X2, X3,
  X4, X5, X6,
  X7, X8
} shiftDoor;

void setupShiftRegister();
void updateShiftRegister();
void setBit(shiftDoor bitIndex, bool value);