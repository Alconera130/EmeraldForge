#include <Arduino.h>

#include "main.h"
#include "features/features.h"

void activateHarvest() {
    if (command != "HARVEST") return;
    
    if (!harvestMillis) harvestMillis = millis();
    Serial.println("Harvesting water...");
    digitalWrite(activatePump, HIGH);

    if (millis() - harvestMillis >= 10000) {
        digitalWrite(activatePump, LOW);
        Serial.println("Harvesting complete.");

        harvestMillis = 0;
        command = "";
    }
}