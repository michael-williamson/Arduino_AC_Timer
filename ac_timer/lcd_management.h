#ifndef LCD_MANAGEMENT_H
#define LCD_MANAGEMENT_H

#include <Arduino.h>

void lcdPrinting(bool rowOne,int columnNumber,String textToPrint){
    int row = rowOne ? 0 : 1 ;
    lcd.setCursor(columnNumber,row);
    lcd.print(textToPrint);
}




#endif