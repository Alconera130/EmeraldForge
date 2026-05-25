#include <Arduino.h>
#include "main.h"
#include "wireless/bluetooth.h"
#include "features/features.h"

NimBLEServer* pServer = nullptr;
NimBLECharacteristic* pCharacteristic = nullptr;

const int pHSensor = 19; // GPIO pin connected to the pH sensor
const int turbiditySensor = 20; // GPIO pin connected to the turbidity sensor
const int activatePump = 21; // GPIO pin to activate the pump
const int activateSensors = 47; // GPIO pin to activate the sensors

bool isDeviceConnected = false; // Flag to track Bluetooth connection status

float previousMillis = 0; // Variable to track the last time sensor data was sent
float harvestMillis = 0; // Variable to track the start time of harvesting
bool isDeepSleepEnabled = false; // Flag to indicate if DeepSleep mode is enabled

String command = ""; // Variable to store the received command
String incoming = ""; // Variable to store incoming Bluetooth data

void setup() {
    Serial.begin(115200);

    NimBLEDevice::init("ESP32_EMERALDFORGE");

    pServer = NimBLEDevice::createServer();
    pServer->setCallbacks(new ServerCallbacks());

    NimBLEService *pService = pServer->createService("1234");
    pCharacteristic =
        pService->createCharacteristic(
            "ABCD",
            NIMBLE_PROPERTY::READ |
            NIMBLE_PROPERTY::WRITE |
            NIMBLE_PROPERTY::NOTIFY
        );

    pCharacteristic->setCallbacks(new CommandCallbacks());

    pService->start();

    NimBLEAdvertising *pAdvertising = NimBLEDevice::getAdvertising();
    pAdvertising->addServiceUUID("1234");
    pAdvertising->start();

    pinMode(pHSensor, INPUT);
    pinMode(turbiditySensor, INPUT);
    pinMode(activatePump, OUTPUT);
    pinMode(activateSensors, OUTPUT);

    Serial.println("Bluetooth device is ready to pair");
}

void loop() {
    bluetooth();
}