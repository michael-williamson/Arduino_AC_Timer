#ifndef BUTTON_SETUP_H
#define BUTTON_SETUP_H

#include <Arduino.h>

#include "cursor_setup.h"
#include "serial_printing.h"
#include "counter_action.h"
#include "timer_position_setup.h"
#include "screen_setups.h"
#include "variable_setup.h"

const int DEBOUNCE_DELAY = 50;  // the debounce time; increase if the output flickers
int lastFlickerableStateBtnOne = LOW;
int lastFlickerableStateBtnTwo = LOW;
int lastFlickerableStateBtnThree = LOW;

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTimeBtnOne = 0;    // the last time the output pin was toggled
unsigned long lastDebounceTimeBtnTwo = 0;    // the last time the output pin was toggled
unsigned long lastDebounceTimeBtnThree = 0;  // the last time the output pin was toggled

void btnOneAction(String screen = "") {
  if (screen == MAIN_SCREEN_TEXT && MAIN_SCREEN == true) {
    setScreens(TIMER_SET_SCREEN_TEXT, MAIN_SCREEN_TEXT);
    initialTimerSetScreenSetup = true;
  }

  if (screen == TIMER_SET_SCREEN_TEXT && TIMER_SET_SCREEN == true) {
    setScreens(MINUTES_SCREEN_TEXT, TIMER_SET_SCREEN_TEXT);
    initialMinutesScreenSetup = true;
    currentDecimalValText = minutesValTenX2Text;
  }

  if (screen == MINUTES_SCREEN_TEXT && MINUTES_SCREEN == true) {
    cursorMover(screen);
    selectDecimalPlaceDisplay(screen);
    // timerPositionSetup(currentDecimalValText);
  }

  if (screen == SECONDS_SCREEN_TEXT && SECONDS_SCREEN == true) {
    cursorMover(screen);
    selectDecimalPlaceDisplay(screen);
    timerPositionSetup(currentDecimalValText);
  }
  if (screen == MINUTES_COUNTER_SCREEN_TEXT && MINUTES_COUNTER_SCREEN == true) {
    setScreens(MINUTES_COUNTER_SCREEN_TEXT, MINUTES_SCREEN_TEXT);
    int decimalPlaceCase = timerPositionSetup(currentDecimalValText);
    counterAction(false, decimalPlaceCase);
  }
  if (screen == SECONDS_COUNTER_SCREEN_TEXT && SECONDS_COUNTER_SCREEN == true) {
    setScreens(SECONDS_COUNTER_SCREEN_TEXT, SECONDS_SCREEN_TEXT);
    int decimalPlaceCase = timerPositionSetup(currentDecimalValText);
    counterAction(false, decimalPlaceCase);
  }
}

void btnTwoAction(String screen = "") {
  if (screen == MAIN_SCREEN_TEXT) {
    // timer.stop();
    // stopPrintingTimer = true;
  }
  if (screen == MINUTES_SCREEN_TEXT && MINUTES_SCREEN == true) {
    setScreens(MINUTES_COUNTER_SCREEN_TEXT, MINUTES_SCREEN_TEXT);
    initialMinutesCountdownSetup = true;
  }
  if (screen == SECONDS_SCREEN_TEXT && SECONDS_SCREEN == true) {
    setScreens(SECONDS_COUNTER_SCREEN_TEXT, SECONDS_SCREEN_TEXT);
    initialSecondsCountdownSetup = true;
  }
  if (screen == TIMER_SET_SCREEN_TEXT && TIMER_SET_SCREEN == true) {
    setScreens(SECONDS_SCREEN_TEXT, TIMER_SET_SCREEN_TEXT);
    initialSecondsScreenSetup = true;
    currentDecimalValText = secondsValTenX2Text;
  }
  if (screen == MINUTES_COUNTER_SCREEN_TEXT && MINUTES_COUNTER_SCREEN == true) {
    setScreens(MINUTES_COUNTER_SCREEN_TEXT, MINUTES_SCREEN_TEXT);
    int decimalPlaceCase = timerPositionSetup(currentDecimalValText);
    counterAction(true, decimalPlaceCase);
  }
  if (screen == SECONDS_COUNTER_SCREEN_TEXT && SECONDS_COUNTER_SCREEN == true) {
    setScreens(SECONDS_COUNTER_SCREEN_TEXT, SECONDS_SCREEN_TEXT);
    int decimalPlaceCase = timerPositionSetup(currentDecimalValText);
    counterAction(true, decimalPlaceCase);
  }
}

void btnThreeAction(String screen = "") {
  if (screen == MAIN_SCREEN_TEXT) {
    setScreens(MAIN_SCREEN_TEXT, TIMER_SET_SCREEN_TEXT);
    timer.start();
    timerCounting = true;
    mainScreenSetup(false);
  }

  if (screen == TIMER_SET_SCREEN_TEXT) {
    setScreens(MAIN_SCREEN_TEXT, TIMER_SET_SCREEN_TEXT);
    initialMainScreenSetup = true;
    initialTimerSetScreenSetup = true;
  }
  if (screen == MINUTES_SCREEN_TEXT && MINUTES_SCREEN == true) {
    columnManager(MINUTES_SCREEN_TEXT);
    setScreens(TIMER_SET_SCREEN_TEXT, MINUTES_SCREEN_TEXT);
    resetDecimalBools(screen);
    initialTimerSetScreenSetup = true;
  }
  if (screen == SECONDS_SCREEN_TEXT && SECONDS_SCREEN == true) {

    columnManager(SECONDS_SCREEN_TEXT);
    setScreens(TIMER_SET_SCREEN_TEXT, SECONDS_SCREEN_TEXT);
    resetDecimalBools(screen);
    initialTimerSetScreenSetup = true;
  }
  if (screen == MINUTES_COUNTER_SCREEN_TEXT && MINUTES_COUNTER_SCREEN == true) {
    setScreens(MINUTES_SCREEN_TEXT, MINUTES_COUNTER_SCREEN_TEXT);
    initialMinutesScreenSetup = true;
    initialColumnSetup = true;
    setColumnOnScreenChange(2);
    updateTimerAction(minutesValTenX2);
    currentDecimalValText = minutesValTenX2Text;
  }
  if (screen == SECONDS_COUNTER_SCREEN_TEXT && SECONDS_COUNTER_SCREEN == true) {
    setScreens(SECONDS_SCREEN_TEXT, SECONDS_COUNTER_SCREEN_TEXT);
    initialSecondsScreenSetup = true;
    initialColumnSetup = true;
    setColumnOnScreenChange(3);
    updateTimerAction(secondsValTenX2);
    currentDecimalValText = secondsValTenX2Text;
  }
}

void btnSetup(String screen = "") {
  // btnOneCurrentState = digitalRead(BUTTON_ONE_PIN);
  // btnTwoCurrentState = digitalRead(BUTTON_TWO_PIN);
  // btnThreeCurrentState = digitalRead(BUTTON_THREE_PIN);
  int btnOneReading = digitalRead(BUTTON_ONE_PIN);
  int btnTwoReading = digitalRead(BUTTON_TWO_PIN);
  int btnThreeReading = digitalRead(BUTTON_THREE_PIN);

  // Serial.println("btn one reading");
  // Serial.println(btnOneReading);

  // BUTTON #1

  if (btnOneReading != btnOneLastState) {
    btnOneLastDebounceTime = millis();
  }

  if ((millis() - btnOneLastDebounceTime) > btnOneDebounceDelay) {

    if (btnOneReading != btnOneCurrentState) {
      btnOneCurrentState = btnOneReading;
      if (btnOneCurrentState == LOW) {
        btnOneAction(screen);
      }
    }
  }

  btnOneLastState = btnOneReading;



  // if (btnOneLastState == HIGH && btnOneCurrentState == LOW) {

  //   btnOneAction(screen);
  // }

  // btnOneLastState = btnOneCurrentState;

  if (btnTwoReading != btnTwoLastState) {
    btnTwoLastDebounceTime = millis();
  }

  if ((millis() - btnTwoLastDebounceTime) > btnTwoDebounceDelay) {
    if (btnTwoReading != btnTwoCurrentState) {
      btnTwoCurrentState = btnTwoReading;
      if (btnTwoCurrentState == LOW) {
        btnTwoAction(screen);
      }
    }
  }

  btnTwoLastState = btnTwoReading;

  // if (btnTwoLastState == HIGH && btnTwoCurrentState == LOW) {

  //   btnTwoAction(screen);
  // }

  // btnTwoLastState = btnTwoCurrentState;

  if (btnThreeReading != btnThreeLastState) {
    btnThreeLastDebounceTime = millis();
  }

  if ((millis() - btnThreeLastDebounceTime) > btnThreeDebounceDelay) {
    if (btnThreeReading != btnThreeCurrentState) {
      btnThreeCurrentState = btnThreeReading;
      if (btnThreeCurrentState == LOW) {
        btnThreeAction(screen);
      }
    }
  }

  btnThreeLastState = btnThreeReading;


  // if (btnThreeLastState == HIGH && btnThreeCurrentState == LOW) {

  //   btnThreeAction(screen);
  // }
  // btnThreeLastState = btnThreeCurrentState;
}



#endif
