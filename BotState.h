#ifndef __H_BOT_STATE__
#define __H_BOT_STATE__
class BotRunner;

class BotState {
    /*
    Try these states:
      ready
      go
      retry
      done
     */
protected:
    BotRunner *context;
public:

    BotState(BotRunner *b) {
        context = b;
    }

    virtual void run() {
        Serial.println("Default BotState running");
    }
};

#endif


