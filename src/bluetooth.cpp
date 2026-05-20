#include "bluetooth.h"
#include "main.h"
#include "calculations.h"

BluetoothSerial SerialBT;

void bluetooth() {
    if (SerialBT.available()) {
        String command = SerialBT.readStringUntil('\n');
        command.trim(); // Remove any leading/trailing whitespace

        if (command == "HARVEST") {
            Serial.println("Harvesting water...");
            digitalWrite(activatePump, HIGH); // Activate the pump
            delay(5000); // Simulate harvesting time
            digitalWrite(activatePump, LOW); // Deactivate the pump
            Serial.println("Harvesting complete.");
        } else {
            Serial.println("Activating sensors...");
            digitalWrite(activateSensors, HIGH); // Activate the sensors

            float pHValue = readVoltage(pHSensor);
            pHValue = 7 + ((2.5 - pHValue) * 0.18) + 0 /* offset */; // Convert voltage to pH value (example calibration)

            float turbidityValue = readVoltage(turbiditySensor);
            if (turbidityValue < 0) turbidityValue = 0; if (turbidityValue > 1) turbidityValue = 1;

            SerialBT.print(pHValue, 2);
            SerialBT.print(",");
            SerialBT.println(turbidityValue, 2);

            Serial.println("================================");
            Serial.print("pH Value: ");
            Serial.print(pHValue, 2);
            Serial.print(", Turbidity Value: ");
            Serial.println(turbidityValue, 2);

            digitalWrite(activateSensors, LOW); // Deactivate the sensors
        }
    }
}