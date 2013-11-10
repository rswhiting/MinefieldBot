#ifndef __H_BOT_RUNNER__
#define __H_BOT_RUNNER__

#include "MotorController.h"
#include "SensorController.h"

class BotState;
class ReadyState;
class BotRunner {
private:
    // current state
    BotState *state;
    // controllers
    MotorController motorController;
    SensorController sensorController;
public:

    void setup();

    void run();

    void setState(BotState *s);
};

#endif



