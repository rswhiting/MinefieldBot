#ifndef TURNSTATE_H
#define	TURNSTATE_H

#include <Arduino.h>
#include "BotState.h"
#include "SensorController.h"
extern HardwareSerial Serial;

class TurnState :
public BotState {
private:
    static const long HALT_TIME = 100;
    static const long BACK_TIME = 500;
    static const long TURN_TIME = 500;
    SensorController::WhichSensors lastSensor;
    unsigned long subStateTimer;
    enum TurnSubState { HALT, BACK, TURN, DONE };
    TurnSubState subState;
public:

    TurnState(BotRunner *b);

    virtual ~TurnState() {
    }
    
    void run();
};


#endif	/* TURNSTATE_H */

