#ifndef RELAY_SETUP_H
#define RELAY_SETUP_H

#include <Arduino.h>



void setRelay(bool relayHigh) {
  if (relayHigh == true) {
    digitalWrite(RELAY_PIN, HIGH);
  } else {
    digitalWrite(RELAY_PIN, LOW);
  }
}

void relayActionTimer() {
  if (timerCountdownComplete == true) {
    setRelay(true);
  }
}





#endif