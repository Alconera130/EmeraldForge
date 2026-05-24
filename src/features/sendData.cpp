#include <Arduino.h>

#include "main.h"
#include "wireless/bluetooth.h"
#include "sensors/sensors.h"
#include "features/features.h"

void sendData() {
    if (!(previousMillis == 0 || millis() - previousMillis >= 1000) && command != "") return;

    previousMillis = millis();
    Serial.println("Activating sensors...");
    digitalWrite(activateSensors, HIGH);

    float pHValue = pH();
    float turbidityValue = turbidity();

    SerialBT.print(pHValue, 2);
    SerialBT.print(",");
    SerialBT.println(turbidityValue, 2);

    Serial.println("================================");
    Serial.print("pH Value: ");
    Serial.print(pHValue, 2);
    Serial.print(", Turbidity Value: ");
    Serial.println(turbidityValue, 2);

    digitalWrite(activateSensors, LOW);
}