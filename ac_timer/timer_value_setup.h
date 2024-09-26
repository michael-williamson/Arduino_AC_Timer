#ifndef TIMER_VALUE_SETUP_H
#define TIMER_VALUE_SETUP_H

#include <Arduino.h>
#include "variable_setup.h"

void updateTimerAction(int val) {
  lcd.setCursor(currentCursorColumn, 0);
  lcd.print(val);
}

void manageTimerDecimalVals(String decimalPlaceText) {

  if (decimalPlaceText == minutesValTenX1Text) {
    minutesValTenX1Bool = true;
    minutesValTenX2Bool = false;
    secondsValTenX1Bool = false;
    secondsValTenX2Bool = false;
  } else if (decimalPlaceText == minutesValTenX2Text) {
    minutesValTenX1Bool = false;
    minutesValTenX2Bool = true;
    secondsValTenX1Bool = false;
    secondsValTenX2Bool = false;
  } else if (decimalPlaceText == secondsValTenX1Text) {
    minutesValTenX1Bool = false;
    minutesValTenX2Bool = false;
    secondsValTenX1Bool = true;
    secondsValTenX2Bool = false;
  } else if (decimalPlaceText == secondsValTenX2Text) {
    minutesValTenX1Bool = false;
    minutesValTenX2Bool = false;
    secondsValTenX1Bool = false;
    secondsValTenX2Bool = true;
  }
}

#endif