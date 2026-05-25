#include <Arduino.h>

#include "main.h"
#include "wireless/bluetooth.h"
#include "sensors/sensors.h"
#include "features/features.h"

void sendData() {
    if (!(previousMillis == 0 || millis() - previousMillis >= 1000) && command != "")
        return;

    previousMillis = millis();

    Serial.println("Activating sensors...");
    digitalWrite(activateSensors, HIGH);

    float pHValue = pH();
    float turbidityValue = turbidity();

    String payload = String(pHValue, 2) + "," + String(turbidityValue, 2);

    pCharacteristic->setValue(payload.c_str());
    pCharacteristic->notify();

    Serial.println("Sent to phone: " + payload);

    digitalWrite(activateSensors, LOW);
}