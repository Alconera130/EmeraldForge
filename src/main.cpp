#include <Arduino.h>
#include "main.h"
#include "wireless/bluetooth.h"

BluetoothSerial SerialBT;

const int pHSensor = 33; // GPIO pin connected to the pH sensor
const int turbiditySensor = 32; // GPIO pin connected to the turbidity sensor
const int activatePump = 21; // GPIO pin to activate the pump
const int activateSensors = 19; // GPIO pin to activate the sensors

float previousMillis = 0; // Variable to track the last time sensor data was sent
float harvestMillis = 0; // Variable to track the start time of harvesting
bool isDeepSleepEnabled = false; // Flag to indicate if DeepSleep mode is enabled

String command = ""; // Variable to store the received command
String incoming = ""; // Variable to store incoming Bluetooth data

void setup() {
    Serial.begin(115200);

    SerialBT.begin("EmeraldForge");

    pinMode(pHSensor, INPUT);
    pinMode(turbiditySensor, INPUT);
    pinMode(activatePump, OUTPUT);
    pinMode(activateSensors, OUTPUT);

    Serial.println("Bluetooth device is ready to pair");
}

void loop() {
    bluetooth();
}