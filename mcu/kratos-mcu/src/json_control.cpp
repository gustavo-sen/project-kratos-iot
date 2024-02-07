#include <ArduinoJson.h>

void createJSON() {
    StaticJsonDocument<200> doc;

    doc["lampNumber"] = 1;
    doc["isOn"] = true;

    char buffer[200];
    serializeJson(doc, buffer);

}
