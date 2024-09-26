#ifndef CURSOR_SETUP_H
#define CURSOR_SETUP_H

#include <Arduino.h>
#include "serial_printing.h"
#include "timer_value_setup.h"
#include "variable_setup.h"


void setDecimalBools(String screen) {

  if (screen == MINUTES_COUNTER_SCREEN_TEXT) {
    minutesValTenX2Bool = true;
  } else if (screen == SECONDS_COUNTER_SCREEN_TEXT) {
    secondsValTenX2Bool = true;
  }
}

void setCursorColumns(int currentColumn, int lastColumn) {
  currentCursorColumn = currentColumn;
  lastCursorColumn = lastColumn;
}

void columnManager(String screen) {
  if (screen == MINUTES_SCREEN_TEXT) {
    lcd.setCursor(minutesScreenTimerCursorDefault, 0);
    setCursorColumns(minutesScreenTimerCursorDefault, minutesScreenTimerCursorDefault + 1);
  } else if (screen == SECONDS_SCREEN_TEXT) {
    lcd.setCursor(secondsScreenTimerCursorDefault, 0);
    setCursorColumns(secondsScreenTimerCursorDefault, secondsScreenTimerCursorDefault + 1);
  }
}

void setColumnOnScreenChange(int decimalPlaceCase) {
  int caseVal = decimalPlaceCase;
  switch (caseVal) {
    case 1:
      currentCursorColumn = 8;
      break;
    case 2:
      currentCursorColumn = 7;
      break;
    case 3:
      currentCursorColumn = 10;
      break;
    case 4:
      currentCursorColumn = 11;
      break;
  }
}


void cursorMover(String screen) {
  if (lastCursorColumn > currentCursorColumn) {
    lastCursorColumn = currentCursorColumn;
    currentCursorColumn = currentCursorColumn + 1;
    lcd.setCursor(currentCursorColumn, 0);
    screen == MINUTES_SCREEN_TEXT ? manageTimerDecimalVals(minutesValTenX1Text) : manageTimerDecimalVals(secondsValTenX1Text);
    currentDecimalValText = screen == MINUTES_SCREEN_TEXT ? minutesValTenX1Text : secondsValTenX1Text;
    return;
  }
  if (lastCursorColumn < currentCursorColumn) {
    lastCursorColumn = currentCursorColumn;
    currentCursorColumn = currentCursorColumn - 1;
    lcd.setCursor(currentCursorColumn, 0);
    screen == MINUTES_SCREEN_TEXT ? manageTimerDecimalVals(minutesValTenX2Text) : manageTimerDecimalVals(secondsValTenX2Text);
    currentDecimalValText = screen == MINUTES_SCREEN_TEXT ? minutesValTenX2Text : secondsValTenX2Text;
    Serial.println("inside last < current");
    Serial.println(currentDecimalValText);
    return;
  }
}

void cursorMoverSeconds() {

  if (lastCursorColumn > currentCursorColumn) {

    lastCursorColumn = currentCursorColumn;
    currentCursorColumn = currentCursorColumn + 1;
    lcd.setCursor(currentCursorColumn, 0);

    secondsValTenX2Bool = false;
    secondsValTenX1Bool = true;
    currentDecimalValText = secondsValTenX1Text;
    return;
  }
  if (lastCursorColumn < currentCursorColumn) {

    lastCursorColumn = currentCursorColumn;
    currentCursorColumn = currentCursorColumn - 1;
    lcd.setCursor(currentCursorColumn, 0);

    secondsValTenX2Bool = true;
    secondsValTenX1Bool = false;
    currentDecimalValText = secondsValTenX2Text;
    return;
  }
}

void cursorSetter(char cursorType[]) {
  if ("minutesArrow") {
    lcd.setCursor(3, 1);
  }
  if ("secondsArrow") {
    lcd.setCursor(3, 1);
  }
  // if ("minutesSecondsRightArrow") {
  //   lcd.setCursor(8, 1);
  // }
}

void rightLeftArrowManager() {
  if (minutesValTenX2Bool == true || secondsValTenX2Bool == true) {
    lcd.createChar(5, rightArrow);
    cursorSetter("minutesArrow");
    lcd.write((byte)5);
  }
  if (minutesValTenX1Bool == true || secondsValTenX1Bool == true) {
    lcd.createChar(4, leftArrow);
    lcd.setCursor(3, 1);
    lcd.write((byte)4);
  }
}

void selectDecimalPlaceDisplay(String screen) {
  if (initialMinutesScreenSetup == true || initialSecondsScreenSetup == true) {
    lcd.createChar(3, upDownArrow);
    lcd.setCursor(8, 1);
    lcd.write((byte)3);

    lcd.createChar(0, backArrow);  // create a new custom character

    lcd.setCursor(14, 1);
    lcd.write((byte)0);  // print the custom char at (2, 0)
    columnManager(screen);
    initialMinutesScreenSetup == true ? manageTimerDecimalVals(minutesValTenX2Text) : manageTimerDecimalVals(secondsValTenX2Text);
    rightLeftArrowManager();
  }

  rightLeftArrowManager();

  lcd.setCursor(currentCursorColumn, 0);
  lcd.blink();
}





void resetDecimalBools(String screen) {
  if (screen == MINUTES_SCREEN_TEXT) {
    minutesValTenX1Bool = false;
    minutesValTenX2Bool = false;
  } else if (screen == SECONDS_SCREEN_TEXT) {
    secondsValTenX1Bool = false;
    secondsValTenX2Bool = false;
  }
}




#endif
