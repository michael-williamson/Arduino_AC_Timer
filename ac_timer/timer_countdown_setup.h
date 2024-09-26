#ifndef TIMER_COUNTDOWN_SETUP_H
#define TIMER_COUNTDOWN_SETUP_H



#include <Arduino.h>
#include "Timer.h"
#include "variable_setup.h"
#include "display_text.h"
#include "serial_printing.h"


int valueMultiplier(int valueOne, int valueTwo) {
  return valueOne * valueTwo;
}

int timerConverter() {
  int totalTime = 0;
  int secondsTotal = 0;
  int minutesTotal = 0;
  int millisecondsTotal = 0;

  secondsTotal = valueMultiplier(secondsValTenX2, 10);
  secondsTotal = secondsTotal + 1;
  minutesTotal = valueMultiplier(minutesValTenX2, 10);
  minutesTotal = minutesTotal + 1;

  millisecondsTotal = secondsTotal * 1000;
  millisecondsTotal = ((minutesTotal / 60) * 1000) + millisecondsTotal;

  return millisecondsTotal;
}

void mainTimer() {
  int millisecondsValue = 0;
  int millisecondsDivided = 0;
  int millisecondsWholeNumberComparator = 0;
  int differenceInMilliseconds;
  millisecondsValue = timer.read();
  millisecondsDivided = millisecondsValue / 1000;
  millisecondsWholeNumberComparator = floor(millisecondsDivided);

  millisecondsWholeNumberComparator = millisecondsWholeNumberComparator * 1000;

  if (millisecondsWholeNumberComparator == lastOneThousandMilliseconds) {
    return;
  }

  differenceInMilliseconds = millisecondsValue - millisecondsWholeNumberComparator;

  if (differenceInMilliseconds < 100) {
    lastOneThousandMilliseconds = millisecondsWholeNumberComparator;
    elapsedOneSecond = true;
  }
}

void timerDisplayUpdate() {
  int val;
  if (elapsedOneSecond == true) {
    val = secondsValTenX1;
    val = val - 1;

    if((secondsValTenX1 + secondsValTenX2  + minutesValTenX1 +minutesValTenX2) == 0 ){
      timerCounting = false;
      timerCountdownComplete = true;
    }

    if (val >= secondsValTenX1MinVal) {
      secondsValTenX1 = secondsValTenX1 - 1;
    } else if (val < secondsValTenX1MinVal && secondsValTenX2 != secondsValTenX2MinVal) {
      secondsValTenX2 = secondsValTenX2 - 1;
      secondsValTenX1 = secondsValTenX1MaxVal;
    } else if (val < secondsValTenX1MinVal && ((secondsValTenX2 - 1) == secondsValTenX2MinVal)) {
      secondsValTenX2 = secondsValTenX1MaxVal;
      secondsValTenX1 = secondsValTenX1MaxVal;
      minutesValTenX1 = minutesValTenX1 - 1;
    }
    // printCountdown("end of if statement timerDisplay update");
    lcdPrintCurrentTimer();
    elapsedOneSecond = false;
  }
}















#endif