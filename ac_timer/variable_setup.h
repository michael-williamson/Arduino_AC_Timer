#ifndef VARIABLE_SETUP_H
#define VARIABLE_SETUP_H

#include <Arduino.h>


// Timer Variables :  Countdown, etc...

bool timerCounting = false;
bool timerPaused = false;
bool timerStopped = false;
bool timerStopButtonInitiated = false;

bool elapsedOneSecond = false;
bool secondsOnlyCountdown = false;

bool timerCountdownComplete = false;

int lastOneThousandMilliseconds = 0;

//Button Press Duration
const int shortPress = 500;
const int longPress = 2000;

long pressedTime = 0;
long releasedTime = 0;

// Defining text chars for states & screens
String setTimer = "Set Timer";
String startTimer = "Start";
String stopTimer = "Stop";
String set = "Set";
String saveText = "save";
String back = "Back";
String minutes = "minutes";
String seconds = "seconds";
String up = "up";
String down = "down";
String timerStart = "Start Timer";
// char circuitOff[] = "Circuit Off";
// char amps[] = "Amps: ";
String timerText = "Timer: ";
String circuit = "Circuit: ";
String on = "On";
String off = "Off";
String btnOne = "Btn One";
String btnTwo = "Btn Two";
String btnThree = "Btn Three";
String MAIN_SCREEN_TEXT = "MAIN_SCREEN";
String TIMER_SET_SCREEN_TEXT = "TIMER_SCREEN";
String MINUTES_SCREEN_TEXT = "MINUTES_SCREEN";
String SECONDS_SCREEN_TEXT = "SECONDS_SCREEN";
String MINUTES_COUNTER_SCREEN_TEXT = "MINUTES_COUNTER_SCREEN_TEXT";
String SECONDS_COUNTER_SCREEN_TEXT = "SECONDS_COUNTER_SCREEN_TEXT";
String TIMER_COMPLETE_SCREEN_TEXT = "TIMER_COMPLETE_SCREEN_TEXT";
String CURRENT_SCREEN_TEXT = "";
String PREVIOUS_SCREEN_TEXT = "";
String btnOneText = "";
String btnTwoText = "";
String btnThreeText = "";

// Boolean Values for determining current screen or state
bool MAIN_SCREEN = true;
bool TIMER_COMPLETE_SCREEN = false;
bool TIMER_SCREEN = false;
bool TIMER_SET_SCREEN = false;
bool MINUTES_SCREEN = false;
bool MINUTES_COUNTER_SCREEN = false;
bool SECONDS_SCREEN = false;
bool SECONDS_COUNTER_SCREEN = false;

bool UPDATE_TIMER = false;

// int btnOneCurrentState = HIGH;
// int btnOneLastState;
// int btnTwoCurrentState = HIGH;
// int btnTwoLastState;
// int btnThreeCurrentState = HIGH;
// int btnThreeLastState;

int btnOneCurrentState;
int btnOneLastState= HIGH;
int btnTwoCurrentState;
int btnTwoLastState = HIGH;
int btnThreeCurrentState;
int btnThreeLastState = HIGH;

unsigned long btnOneLastDebounceTime = 0;  
unsigned long btnOneDebounceDelay = 25;   
unsigned long btnTwoLastDebounceTime = 0;  
unsigned long btnTwoDebounceDelay = 25;   
unsigned long btnThreeLastDebounceTime = 0;  
unsigned long btnThreeDebounceDelay = 25;   

// int btnOneCurrentState;
// int btnOneLastState;
// int btnTwoCurrentState;
// int btnTwoLastState;
// int btnThreeCurrentState;
// int btnThreeLastState;



// Timer Values: (Minutes, Seconds, ...)
int minutesValTenX1 = 0;
int minutesValTenX2 = 0;
int secondsValTenX1 = 0;
int secondsValTenX2 = 0;

int secondsValTenX1MaxVal = 9;
int secondsValTenX1MinVal = 0;
int secondsValTenX2MaxVal = 5;
int secondsValTenX2MinVal = 0;
int minutesValTenX1MaxVal = 9;
int minutesValTenX1MinVal = 0;
int minutesValTenX2MaxVal = 2;

int updateTimerValue;

int decimalTenValue = 10;
int decimalOneValue = 1;

int wholeTimerInSeconds = 0;

// ------ divide or multiply by this to get whole value
int secondsConvert = 60;

String minutesValTenX1Text = "minutesValTenX1";
String minutesValTenX2Text = "minutesValTenX2";
String secondsValTenX1Text = "secondsValTenX1";
String secondsValTenX2Text = "secondsValTenX2";

String currentDecimalValText = "";

bool minutesValTenX1Bool = false;
bool minutesValTenX2Bool = false;
bool secondsValTenX1Bool = false;
bool secondsValTenX2Bool = false;

// Cursor Tracking
int currentCursorColumn;
int lastCursorColumn;

bool initialColumnSetup = true;
bool initialMainScreenSetup = true;
bool initialTimerSetScreenSetup = false;
bool initialMinutesScreenSetup = false;
bool initialMinutesCountdownSetup = false;
bool initialSecondsScreenSetup = false;
bool initialSecondsCountdownSetup = false;

int minutesScreenTimerCursorDefault = 7;
int secondsScreenTimerCursorDefault = 10;





#endif
