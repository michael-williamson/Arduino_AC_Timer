#ifndef SCREEN_SETUPS_H
#define SCREEN_SETUPS_H

#include <Arduino.h>
#include "variable_setup.h"
#include "lcd_management.h"

void mainScreenSetup(bool initialSetup = false) {
  if (initialSetup == true) {
    lcd.clear();          // clear display
    lcd.setCursor(0, 0);  // move cursor to   (0, 0)
    lcd.print(timerText);
    lcdPrinting(false, 0, setTimer);
    lcd.setCursor(11, 1);
    lcd.print(startTimer);
    initialMainScreenSetup = false;
  }


  if (timerCounting == true && timerStopButtonInitiated == false) {
    lcdPrinting(false, 0, stopTimer);
    lcdPrinting(false,4,"     ");
    timerStopButtonInitiated = true;
  }
}


void setupMinutesCountdown() {


  lcd.createChar(4, downArrow);
  lcd.setCursor(2, 1);
  lcd.write((byte)4);

  lcd.createChar(3, upArrow);
  lcd.setCursor(7, 1);
  lcd.write((byte)3);

  lcd.setCursor(11, 1);
  lcd.print(saveText);

  lcd.setCursor(currentCursorColumn, 0);


  lcd.blink();
}

void setupSecondsCountdown() {


  lcd.createChar(4, downArrow);
  lcd.setCursor(2, 1);
  lcd.write((byte)4);

  lcd.createChar(3, upArrow);
  lcd.setCursor(7, 1);
  lcd.write((byte)3);

  lcd.setCursor(11, 1);
  lcd.print(saveText);

  lcd.setCursor(currentCursorColumn, 0);
  lcd.noCursor();
}

int screenSelector(String screen) {
  int caseInt;

  if (screen == MAIN_SCREEN_TEXT) {
    caseInt = 0;
  } else if (screen == TIMER_SET_SCREEN_TEXT) {
    caseInt = 1;
  } else if (screen == MINUTES_SCREEN_TEXT) {
    caseInt = 2;
  } else if (screen == SECONDS_SCREEN_TEXT) {
    caseInt = 3;
  } else if (screen == MINUTES_COUNTER_SCREEN_TEXT) {
    caseInt = 4;
  } else if (screen == SECONDS_COUNTER_SCREEN_TEXT) {
    caseInt = 5;
  } else if (screen == "") {
    caseInt = 6;
  }
  return caseInt;
}

void screenBoolSelector(bool set, int caseInt) {
  switch (caseInt) {
    case 0:
      MAIN_SCREEN = set;
      break;
    case 1:
      TIMER_SET_SCREEN = set;
      break;
    case 2:
      MINUTES_SCREEN = set;
      break;
    case 3:
      SECONDS_SCREEN = set;
      break;
    case 4:
      MINUTES_COUNTER_SCREEN = set;
      break;
    case 5:
      SECONDS_COUNTER_SCREEN = set;
      break;
  }
}

void setScreens(String newScreen, String lastScreen) {
  int case1 = screenSelector(lastScreen);
  screenBoolSelector(false, case1);
  int case2 = screenSelector(newScreen);
  screenBoolSelector(true, case2);
}










#endif