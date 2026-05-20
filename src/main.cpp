#include <Arduino.h>
#include "main.h"
#include "bluetooth.h"

const int pHSensor = 13; // GPIO pin connected to the pH sensor
const int turbiditySensor = 12; // GPIO pin connected to the turbidity sensor
const int activatePump = 14; // GPIO pin to activate the pump
const int activateSensors = 27; // GPIO pin to activate the sensors

void setup() {
    Serial.begin(115200);

    pinMode(pHSensor, INPUT);
    pinMode(turbiditySensor, INPUT);
    pinMode(activatePump, OUTPUT);
    pinMode(activateSensors, OUTPUT);

    SerialBT.begin("ESP32_EMERALDFORGE"); // Bluetooth device name
    Serial.println("Bluetooth device is ready to pair");
}

void loop() {
    bluetooth();

    digitalWrite(activateSensors, LOW); // Ensure sensors are deactivated when not in use
    delay(600); // Delay to avoid overwhelming the Bluetooth connection
}