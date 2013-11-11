#include "TurnState.h"
#include "BotRunner.h"
#include "MotorController.h"
#include "GoState.h"

TurnState::TurnState(BotRunner* b) : BotState(b) {
    Serial.println("Entering Turn State: halting all engines");
    context->getMotorController().setRunModes(MotorController::ALL, RELEASE);
    SensorController::WhichSensors sensor = context->getSensorController().triggered();
    Serial.print("Triggered on: ");
    Serial.println(sensor);
}

void TurnState::run() {
    // check sensors
    if(context->getSensorController().triggered() == SensorController::NONE)
    {
        context->setState(new GoState(context));
        delete this;
    }
}
