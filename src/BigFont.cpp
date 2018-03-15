/*
 * BigFont.cpp - Big Font library for Arduino - Version 0.21
 *
 * Derived from Stepper.cpp
 *   Original library        (0.1)   by Tom Igoe et al...
 * Modified work Copyright 2017 Gianluca Cassarino
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "BigFont.h"
#include <LiquidCrystal.h>

/*
 * Big Font constructor
 */
BigFont::BigFont(uint8_t size)
{
  if(size > 4){ size = 4; }
  if(size < 2){ size = 2; }
  this->_fontSize = size;
}

/*
 * Load the special characters in LCD driver chip
 * Called once on configuring custom characters
 */
#ifndef LiquidCrystal_I2C_h // New liquid crystal library
void BigFont::loadchars(LiquidCrystal& lcd)
#else
void BigFont::loadchars(LiquidCrystal_I2C& lcd)
#endif
{
  if(this->_fontSize == 2) {
    // FONT 3x2
    // load custom characters into display controller memory
    lcd.createChar(0, custchar2[0]);
    lcd.createChar(1, custchar2[1]);
    lcd.createChar(2, custchar2[2]);
    lcd.createChar(3, custchar2[3]);
    lcd.createChar(4, custchar2[4]);
    lcd.createChar(5, custchar2[5]);
    lcd.createChar(6, custchar2[6]);
    lcd.createChar(7, custchar3[7]); // bell (uguale per tutti i font)
  } else {
    // FONTS 3x3 e 4x4
    // load custom characters into display controller memory
    lcd.createChar(0, custchar3[0]);
    lcd.createChar(1, custchar3[1]);
    lcd.createChar(2, custchar3[2]);
    lcd.createChar(3, custchar3[3]);
    lcd.createChar(4, custchar3[4]);
    lcd.createChar(5, custchar3[5]);
    lcd.createChar(6, custchar3[6]);
    lcd.createChar(7, custchar3[7]);
  }
}

// print blank character
#ifndef LiquidCrystal_I2C_h // New liquid crystal library
void BigFont::printblankchar(LiquidCrystal& lcd, byte col, byte row)
#else
void BigFont::printblankchar(LiquidCrystal_I2C& lcd, byte col, byte row)
#endif
{
   for(int i = 0; i < 4; i++) // for each row
   {
      lcd.setCursor(col, row + i);
      for(int j = 0; j < 4; j++) // for each column
      {
        lcd.write(254);  // blank char
      } // for(i...
   } // for(j...
} // printblankchar()

// digit 0-9; col, row in LCD character, symbol
#ifndef LiquidCrystal_I2C_h // New liquid crystal library
void BigFont::printbigchar(LiquidCrystal& lcd, byte digit, byte col, byte row)
#else
void BigFont::printbigchar(LiquidCrystal_I2C& lcd, byte digit, byte col, byte row)
#endif
{
  if ((digit > 9) | (digit < 0)) return;
  // loop over the font and write to lcd
  if(this->_fontSize == 2){ // 3x2 fonts
    for (int i = 0; i < this->_fontSize; i++)    // for each row
    {
      lcd.setCursor(col, row + i); //set the row address
      for (int j = 0; j < 3; j++)  // for each column of font
      {
        lcd.write(this->bignums3x2[digit][i][j]);
      }
    }
  } else if(this->_fontSize == 3){ // 3x3 fonts
    for (int i = 0; i < this->_fontSize; i++)    // for each row
    {
      lcd.setCursor(col, row + i); //set the row address
      for (int j = 0; j < 3; j++)  // for each column of font
      {
        lcd.write(this->bignums3x3[digit][i][j]);
      }
    }
  } else { // 4x4 fonts
    for (int i = 0; i < this->_fontSize; i++)    // for each row
    {
      lcd.setCursor(col, row + i); //set the row address
      for (int j = 0; j < 4; j++)  // for each column of font
      {
        lcd.write(this->bignums[digit][i][j]);
      }
    }
  }
}

uint8_t BigFont::getFontSize(){
  return this->_fontSize;
}

void BigFont::setFontSize(uint8_t size) {
  if(size > 4){ size = 4; }
  if(size < 2){ size = 2; }
  this->_fontSize = size;
}

// version() returns the version of the library:
int BigFont::version(void) {
  return 2;
}
