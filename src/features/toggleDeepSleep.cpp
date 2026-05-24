#include <Arduino.h>

#include "main.h"
#include "features/features.h"

void toggleDeepSleep() {
    if (!(command == "true" || command == "false")) return;

    Serial.println("Received command: " + command);

    isDeepSleepEnabled = (command == "true");
    Serial.println("DeepSleep mode is now " + String(isDeepSleepEnabled ? "enabled" : "disabled"));
}