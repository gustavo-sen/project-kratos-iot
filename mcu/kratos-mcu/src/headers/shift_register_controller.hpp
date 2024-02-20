#pragma once

typedef enum{
  REG_XO_1,REG_XO_2,REG_XO_3,REG_XO_4,REG_XO_5,REG_XO_6,REG_XO_7,REG_XO_8
} REG_XOS;

void setupShiftRegister();
void updateShiftRegister();
void setBit(REG_XOS bitIndex, bool value);