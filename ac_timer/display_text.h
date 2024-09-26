#ifndef DISPLAY_TEXT_H
#define DISPLAY_TEXT_H

#include <Arduino.h>
#include "button_setup.h"
#include "cursor_setup.h"



void upDownArrowsDisplay() {
  // placing arrows
  lcd.createChar(1, upArrow);  // create a new custom character

  lcd.setCursor(4, 1);
  lcd.write((byte)1);  // print the custom char at (2, 0)

  lcd.createChar(2, downArrow);  // create a new custom character

  lcd.setCursor(10, 1);
  lcd.write((byte)2);  // print the custom char at (2, 0)
}

void lcdPrintTimerReset(bool defaultTimer, bool zeroedTimer) {
  int minutesValTenX2 = 0;
  int minutesValTenX1 = 0;
  int secondsValTenX2 = 0;
  int secondsValTenX1 = 0;

  if (defaultTimer) {
    minutesValTenX2 = 1;
  }

  lcd.setCursor(0, 0);
  lcd.print("Timer: ");
  lcd.setCursor(7, 0);
  lcd.print(minutesValTenX2);
  lcd.setCursor(8, 0);
  lcd.print(minutesValTenX1);
  lcd.setCursor(9, 0);
  lcd.print(":");
  lcd.setCursor(10, 0);
  lcd.print(secondsValTenX2);
  lcd.setCursor(11, 0);
  lcd.print(secondsValTenX1);
}

void lcdPrintCurrentTimer() {
  lcd.setCursor(0, 0);
  lcd.print("Timer: ");
  lcd.setCursor(7, 0);
  lcd.print(minutesValTenX2);
  lcd.setCursor(8, 0);
  lcd.print(minutesValTenX1);
  lcd.setCursor(9, 0);
  lcd.print(":");
  lcd.setCursor(10, 0);
  lcd.print(secondsValTenX2);
  lcd.setCursor(11, 0);
  lcd.print(secondsValTenX1);
}

#endif
