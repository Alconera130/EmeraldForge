#include <Arduino.h>
#include "calculations.h"

float readVoltage(int pin) {
    long sum = 0;

    for (int i = 0; i < 20; i++) {
        sum += analogRead(pin);
        delay(10);
    }

    float avg = sum / 20.0;
    return (avg / 4095.0) * 3.3;
}