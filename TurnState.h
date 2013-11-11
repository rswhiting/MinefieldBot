#ifndef TURNSTATE_H
#define	TURNSTATE_H

#include <Arduino.h>
#include "BotState.h"
extern HardwareSerial Serial;

class TurnState :
public BotState {
public:

    TurnState(BotRunner *b);

    virtual ~TurnState() {
    }
    
    void run();
};


#endif	/* TURNSTATE_H */

