#ifndef __H_BOT_STATE__
#define __H_BOT_STATE__
class BotRunner;
class BotState {
    /*
    Try these states:
      ready
      go
      veer
      retry
      done
     */
public:

    virtual void run(BotRunner *b) {
        Serial.println("Default BotState running");
    }
};

#endif


