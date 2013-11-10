#include <Arduino.h>
#include "BotRunner.h"

BotRunner *runner;

void setup() {
    runner = new BotRunner();
    runner->setup();
}

void loop() {
    runner->run();
}