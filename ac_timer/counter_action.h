#ifndef COUNTER_ACTION_H
#define COUNTER_ACTION_H

#include <Arduino.h>
#include "variable_setup.h"
#include "serial_printing.h"

int counterIncreaseDecrease(int val, bool up,int max) {
  int newVal = val;

  if (up == true) {

    newVal = newVal + 1;
    if (newVal >= max) {
      return max -1;
    }

  } else if (up == false) {

    newVal = newVal - 1;

    if (newVal <= -1) {
      return 0;
    }
  }

  UPDATE_TIMER = true;

  return newVal;
}


void counterAction(bool up, int decimalPlace) {
  switch (decimalPlace) {
    case 1:
      minutesValTenX2 = counterIncreaseDecrease(minutesValTenX2, up,2);
      updateTimerValue = minutesValTenX2;
      break;
    case 2:
      minutesValTenX1 = counterIncreaseDecrease(minutesValTenX1, up,10);
      updateTimerValue = minutesValTenX1;
      break;
    case 3:
      secondsValTenX2 = counterIncreaseDecrease(secondsValTenX2, up,6);
      updateTimerValue = secondsValTenX2;
      break;
    case 4:
      secondsValTenX1 = counterIncreaseDecrease(secondsValTenX1, up,10);
      updateTimerValue = secondsValTenX1;
      break;
  }
}

#endif