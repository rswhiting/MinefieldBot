#include "BotRunner.h"
#include "BotState.h"
#include "ReadyState.h"
extern HardwareSerial Serial;

void BotRunner::setup() {
    setState(new ReadyState(this));
    Serial.println("BotRunner setup complete");
}

void BotRunner::run() {
    state->run();
}

void BotRunner::setState(BotState *s) {
    state = s;
}
