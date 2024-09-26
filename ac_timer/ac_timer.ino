// lcd Lirbary setup

#include <LiquidCrystal_I2C.h>
// #include "screen_setups.h"

#include <Wire.h>

extern LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C address 0x27, 16 column and 2 rows


// Timer Library by Stefan Staub
// Timer Library Documentation Link : https://github.com/sstaub/Timer
#include "Timer.h"
Timer timer;


#define SCREEN_WIDTH 128  // OLED display width,  in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

bool stopPrintingTimer = false;



// Arduino Inputs for Interface Buttons
const int BUTTON_ONE_PIN = 4;
const int BUTTON_TWO_PIN = 5;
const int BUTTON_THREE_PIN = 6;
const int RELAY_PIN = 9;

#include "special_char_setup.h"

#include "variable_setup.h"
#include "button_setup.h"

#include "screen_setups.h"
#include "display_text.h"
#include "cursor_setup.h"
#include "timer_value_setup.h"
#include "timer_countdown_setup.h"
#include "relay_setup.h"


void setup() {
  // Serial Setup
  Serial.begin(9600);

  // Relay Setup
  pinMode(RELAY_PIN, OUTPUT);
  setRelay(false);



  // LCD Setup

  lcd.init();  // initialize the lcd
  lcd.backlight();



  // assigning buttons as INPUT_PULLUP
  pinMode(BUTTON_ONE_PIN, INPUT_PULLUP);
  pinMode(BUTTON_TWO_PIN, INPUT_PULLUP);
  pinMode(BUTTON_THREE_PIN, INPUT_PULLUP);
  pinMode(RELAY_PIN, OUTPUT);
}


void loop() {


  if (timerCounting == true) {
    mainTimer();
    timerDisplayUpdate();
    if (digitalRead(RELAY_PIN) == LOW) {
      setRelay(true);
    }
  }

  if (timerCountdownComplete == true) {
    setRelay(false);
  }



  if (MAIN_SCREEN == true) {
    if (initialMainScreenSetup == true) {
      mainScreenSetup(initialMainScreenSetup);
      lcdPrintCurrentTimer();
      lcd.noBlink();
    }

    if (timerStopButtonInitiated == true && timerCounting == false) {
      mainScreenSetup(true);
      lcdPrintCurrentTimer();
      lcd.noBlink();
      timerStopButtonInitiated = false;
    }
    btnSetup(MAIN_SCREEN_TEXT);
  }

  // Set Timer Screen

  if (TIMER_SET_SCREEN == true) {
    // claar LCD
    if (initialTimerSetScreenSetup == true) {
      lcd.clear();  // clear display
      lcdPrintCurrentTimer();

      btnOneText = minutes;
      btnTwoText = "sec";
      btnThreeText = back;

      lcd.setCursor(0, 1);
      lcd.print(btnOneText);

      lcd.setCursor(8, 1);
      lcd.print(btnTwoText);


      lcd.createChar(0, backArrow);  // create a new custom character

      lcd.setCursor(14, 1);
      lcd.write((byte)0);  // print the custom char at (2, 0)

      lcd.noBlink();
      initialTimerSetScreenSetup = false;
    }
    btnSetup(TIMER_SET_SCREEN_TEXT);
  }

  // ---------------- Setting Minutes
  // --- I need to account for one decimal place minutes, seconds. 00:00;  If less than 10 assign zero to that cursor spot otherwise
  // --- print the entire value of the variable.

  if (MINUTES_SCREEN == true) {
    if (initialMinutesScreenSetup == true) {
      lcd.clear();  // clear display
      lcdPrintCurrentTimer();
      selectDecimalPlaceDisplay(MINUTES_SCREEN_TEXT);

      initialMinutesScreenSetup = false;
    }



    if (initialColumnSetup == true) {
      setCursorColumns(7, 8);
      columnManager(MINUTES_SCREEN_TEXT);
      initialColumnSetup = false;
    }
    btnSetup(MINUTES_SCREEN_TEXT);
    // upDownArrowDisplay();
  }

  if (SECONDS_SCREEN == true) {
    if (initialSecondsScreenSetup == true) {
      lcd.clear();  // clear display
      lcdPrintCurrentTimer();
      selectDecimalPlaceDisplay(SECONDS_SCREEN_TEXT);

      initialSecondsScreenSetup = false;
    }



    if (initialColumnSetup == true) {
      setCursorColumns(10, 11);
      initialColumnSetup = false;
    }
    btnSetup(SECONDS_SCREEN_TEXT);
    // upDownArrowDisplay();
  }

  if (MINUTES_COUNTER_SCREEN == true) {
    if (initialMinutesCountdownSetup == true) {
      setDecimalBools(MINUTES_COUNTER_SCREEN_TEXT);
      lcd.clear();
      lcdPrintCurrentTimer();
      setupMinutesCountdown();
      initialMinutesCountdownSetup = false;
    }
    if (UPDATE_TIMER == true) {
      updateTimerAction(updateTimerValue);
      UPDATE_TIMER = false;
    }
    btnSetup(MINUTES_COUNTER_SCREEN_TEXT);
  }

  if (SECONDS_COUNTER_SCREEN == true) {
    if (initialSecondsCountdownSetup == true) {
      setDecimalBools(SECONDS_COUNTER_SCREEN_TEXT);
      lcd.clear();
      lcdPrintCurrentTimer();
      setupSecondsCountdown();
      initialSecondsCountdownSetup = false;
    }
    if (UPDATE_TIMER == true) {
      updateTimerAction(updateTimerValue);
      UPDATE_TIMER = false;
    }
    btnSetup(SECONDS_COUNTER_SCREEN_TEXT);
  }

  // --------------- Setting Seconds
  // ---
  // ---

  // ------------



  // Display after Commands











  // end of loop parenthesis
}



// copy paste code
// btnOneCurrentState = digitalRead(BUTTON_ONE_PIN);
//   btnTwoCurrentState = digitalRead(BUTTON_TWO_PIN);
//   btnThreeCurrentState = digitalRead(BUTTON_THREE_PIN);

//   if(btnOneLastState == HIGH && btnOneCurrentState == LOW)
//     Serial.println("The button is pressed");
//   else if(btnOneLastState == LOW && btnOneCurrentState == HIGH)
//     Serial.println("The button is released");

//   // save the the last state
//   btnOneLastState = btnOneCurrentState;




//         if(btnTwoLastState == HIGH && btnTwoCurrentState == LOW)
//     Serial.println("The button is pressed");
//   else if(btnTwoLastState == LOW && btnTwoCurrentState == HIGH)
//     Serial.println("The button is released");

//   // save the the last state
//   btnTwoLastState = btnTwoCurrentState;





//         if(btnThreeLastState == HIGH && btnThreeCurrentState == LOW)
//     Serial.println("The button is pressed");
//   else if(btnThreeLastState == LOW && btnThreeCurrentState == HIGH)
//     Serial.println("The button is released");

//   // save the the last state
//   btnThreeLastState = btnThreeCurrentState;

// void updateTimerAction() {

//   lcd.setCursor(currentCursorColumn, 0);
//   if (currentCursorColumn == 7) {
//     lcd.print(minutesValTenX2);
//   } else if (currentCursorColumn == 8) {
//     lcd.print(minutesValTenX1);
//   } else if (currentCursorColumn == 10) {
//     lcd.print(secondsValTenX2);
//   } else if (currentCursorColumn == 1) {
//     lcd.print(secondsValTenX1);
//   }
// }
