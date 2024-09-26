#ifndef SERIAL_PRINTING_H
#define SERIAL_PRINTING_H

#include <Arduino.h>
#include "variable_setup.h"

void printPlaceFinder(String message) {
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.print("Where am I: ");
  Serial.print(message);
  Serial.println("");
  Serial.println("");
}

void printCounterValue(String message, int val) {
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("________________   beginning of printerCounterValue   _________________");
  Serial.println("");
  Serial.println("printing counter value");
  Serial.println("");
  Serial.print("Where am I? :  ");
  Serial.print(message);
  Serial.println("");
  Serial.print("Value is : ");
  Serial.print(val);
  Serial.println("");
  Serial.println("");
  Serial.println("________________   end of printerCounterValue   _________________");
  Serial.println("");
}

void printCurrentScreens() {
  Serial.println(" _____________  ");
  Serial.print("Main Screen: ");
  Serial.print(MAIN_SCREEN);
  Serial.println("");

  Serial.print("Timer Set Screen: ");
  Serial.print(TIMER_SET_SCREEN);
  Serial.println("");

  Serial.print("Minutes Screen: ");
  Serial.print(MINUTES_SCREEN);
  Serial.println("");

  Serial.print("Seconds Screen: ");
  Serial.print(SECONDS_SCREEN);
  Serial.println("");

  Serial.print("Minutes Counter Screen: ");
  Serial.print(MINUTES_COUNTER_SCREEN);
  Serial.println("");

  Serial.print("Seconds Counter Screen: ");
  Serial.print(SECONDS_COUNTER_SCREEN);
  Serial.println("");
}

void printDecimalIntValue() {
  Serial.println(" _____________  ");
  Serial.print("Minutes Value 10: ");
  Serial.print(minutesValTenX2);
  Serial.println("");
  Serial.print("Minutes Value 1: ");
  Serial.print(minutesValTenX1);
  Serial.println("");
  Serial.print("Seconds Value 10: ");
  Serial.print(secondsValTenX2);
  Serial.println("");
  Serial.print("Seconds Value 1: ");
  Serial.print(secondsValTenX1);
  Serial.println("");
}

void printTimerCountdownCompletion() {
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("________________   Timer Countdown Complete Variable    _________________");
  Serial.println("");
  Serial.print("Timer Complete: ");
  Serial.print(timerCountdownComplete);
  Serial.println("");
  Serial.println("________________   end of printerCounterValue   _________________");
  Serial.println("");
}



void boolValsForTime(String message = "") {
  Serial.println(" _____________  ");
  Serial.println(message);
  Serial.println(" _____________  ");
  Serial.print("minutesValTenX2Bool: ");
  Serial.print(minutesValTenX2Bool);
  Serial.println("");
  Serial.println(" _____________  ");
  Serial.print("minutesValTenX1Bool: ");
  Serial.print(minutesValTenX1Bool);
  Serial.println("");
  Serial.println(" _____________  ");
  Serial.print("secondsValTenX2Bool: ");
  Serial.print(secondsValTenX2Bool);
  Serial.println("");
  Serial.println(" _____________  ");
  Serial.print("secondsValTenX1Bool: ");
  Serial.print(secondsValTenX1Bool);
  Serial.println("");
}

void printCursorColumns(String idenText) {
  Serial.println("");
  Serial.println("");
  Serial.println(" _____________  ");
  Serial.println(idenText);
  Serial.print("current column: ");
  Serial.print(currentCursorColumn);
  Serial.println("");
  Serial.print("last column: ");
  Serial.print(lastCursorColumn);
  Serial.println("");
  Serial.println(" _____________  ");
  Serial.println("");
}

void printCountdown(String message = "") {
  Serial.println("");
  Serial.println("");
  Serial.println(" _____________  Printing Countdown  __________________  ");
  Serial.println("");
  Serial.println("");
  Serial.print("Where am I :  ");
  Serial.print(message);
  Serial.println("");
  Serial.println("");
  Serial.println(" _____________  Printing Countdown ending  __________________  ");
}

#endif