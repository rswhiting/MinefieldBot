#include "GoState.h"
#include "BotRunner.h"
#include "MotorController.h"
#include "TurnState.h"

GoState::GoState(BotRunner *b) : BotState(b) {
    Serial.println("Entering Go State: all engines ahead full");
    context->getMotorController().setRunModes(MotorController::ALL, FORWARD);
}

void GoState::run() {
    // check sensors
    if(context->getSensorController().triggered() != SensorController::NONE)
    {
        context->setState(new TurnState(context));
        delete this;
    }
}
