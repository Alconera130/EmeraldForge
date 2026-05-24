#include <Arduino.h>

#include "wireless/bluetooth.h"
#include "main.h"
#include "features/features.h"

void readLine() {
    while (SerialBT.available() && command == "") {
        char c = SerialBT.read();

        if (c == '\n') {
            incoming.trim();

            if (!incoming.isEmpty()) {
                command = incoming;

                Serial.println("Received command: " + incoming);
            }

            incoming = "";
        } else {
            incoming += c;
        }
    }
}