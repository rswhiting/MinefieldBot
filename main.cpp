#include <Arduino.h>
#include "BotRunner.h"

BotRunner runner;

void setup() {
    Serial.begin(9600);
    runner.setup();
}

void loop() {
    runner.run();
}