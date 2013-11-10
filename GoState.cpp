#include "GoState.h"
#include "BotRunner.h"
#include "MotorController.h"

GoState::GoState(BotRunner *b) : BotState(b) {
    Serial.println("Entering Go State: all engines ahead full");
    context->getMotorController().setSpeeds(MotorController::ALL, 255);
    context->getMotorController().setRunModes(MotorController::ALL, FORWARD);
}

void GoState::run() {
    // check sensors
}