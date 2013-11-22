#ifndef GOSTATE_H
#define	GOSTATE_H

#include <Arduino.h>
#include "BotState.h"
extern HardwareSerial Serial;

class GoState :
public BotState {
private:
    static const long MIN_GO_TIME = 1000;
    unsigned long timer;
public:

    GoState(BotRunner *b);

    virtual ~GoState() {
    }
    
    void run();
};


#endif	/* GOSTATE_H */

