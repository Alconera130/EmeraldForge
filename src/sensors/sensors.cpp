#include <Arduino.h>

#include "main.h"
#include "sensors/sensors.h"

float pH() {
    float pHValue = 0;

    for (int i = 0; i < 20; i++) {
        pHValue += analogRead(pHSensor);
        delay(10);
    }

    pHValue = ((pHValue / 20) * 3.3 / 4095.0); pHValue = pHValue * 1.5;
    pHValue = 7 + ((2.5 - pHValue) / 0.18);
    if (pHValue < 0) pHValue = 0; if (pHValue > 14) pHValue = 14;

    return pHValue;
}

float turbidity() {
    float turbidityValue = 0;

    for (int i = 0; i < 20; i++) {
        turbidityValue += analogRead(turbiditySensor);
        delay(10);
    }

    turbidityValue = ((turbidityValue / 20) / 4095.0) * 100;
    if (turbidityValue < 0) turbidityValue = 0; if (turbidityValue > 100) turbidityValue = 100;

    return turbidityValue;
}