#ifndef TIMER_POSITION_SETUP_H
#define TIMER_POSITION_SETUP_H

#include <Arduino.h>
#include "variable_setup.h"

int timerPositionSetup(String currentPlaceText){
  int caseVal;

  if (currentPlaceText == minutesValTenX2Text) {
    caseVal = 1;
  } else if (currentPlaceText == minutesValTenX1Text) {
    caseVal = 2;
  } else if (currentPlaceText == secondsValTenX2Text) {
    caseVal = 3;
  } else if (currentPlaceText == secondsValTenX1Text) {
    caseVal = 4;
  }
  return caseVal;
}

int timerPositionSetupAction() {
  int caseVal;

  if (minutesValTenX2Bool == true) {
    caseVal = 1;
  } else if (minutesValTenX1Bool == true) {
    caseVal = 2;
  } else if (secondsValTenX2Bool == true) {
    caseVal = 3;
  } else if (secondsValTenX1Bool == true) {
    caseVal = 4;
  }
  return caseVal;
}



#endif