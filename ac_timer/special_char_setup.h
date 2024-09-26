#ifndef SPECIAL_CHAR_SETUP_H
#define SPECIAL_CHAR_SETUP_H

#include <Arduino.h>


// Custom Characters


byte downArrow[8] = {
  0b11111,
  0b11111,
  0b01110,
  0b01110,
  0b00100,
  0b00000,
  0b00000,
  0b00000
};

byte upArrow[8] = {
  0b00100,
  0b01110,
  0b01110,
  0b11111,
  0b11111,
  0b00000,
  0b00000,
  0b00000
};

byte upDownArrow[8] = {
  0b00000,
	0b11100,
	0b11100,
	0b01000,
	0b00010,
	0b00111,
	0b00111,
	0b00000
};

byte backArrow[8] = {
  0b11111,
  0b00001,
  0b00001,
  0b00101,
  0b01111,
  0b11111,
  0b01100,
  0b00100
};

byte leftArrow[8] = {
  0b00000,
  0b00001,
  0b00111,
  0b11111,
  0b11111,
  0b00111,
  0b00001,
  0b00000
};

byte rightArrow[8] = {
  0b00000,
  0b11000,
  0b11000,
  0b11110,
  0b11111,
  0b11110,
  0b11000,
  0b00000
};

// from this website there is a character creator https://chareditor.com/

// byte name0x2[] = { B10000, B00000, B00000, B00000, B00000, B11011, B10010, B11010 };
// byte name0x0[] = { B01101, B01001, B00101, B01101, B00000, B01110, B00100, B00100 };
// byte name0x1[] = { B11011, B00001, B10001, B11001, B00000, B10111, B10101, B10101 };



#endif