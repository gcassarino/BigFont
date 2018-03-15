/*
 * BigFont.h - Big Font library for Arduino - Version 0.21
 *
 * Derived from https://github.com/wa1hco/BigFont
 *   Original library        (0.1)   by Tom Igoe and others
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
 *
 * Drives 4 row, character type Liquid Crystal Displays with 3x2, 3x3, 4x4 fonts of special symbols
 *
 */

// ensure this library description is only included once
#ifndef BigFont_h
#define BigFont_h
#include <LiquidCrystal.h>

#ifndef LiquidCrystal_h // Using the new LiquidCrystal library
  #ifdef LiquidCrystal_4bit_h || LiquidCrystal_I2C_h || _LIQUIDCRYSTAL_SR_ || _LIQUIDCRYSTAL_SR2W_ || _LIQUIDCRYSTAL_SR3W_H_
    #include <LiquidCrystal.h>
    // #include <LiquidCrystal_I2C.h>
  #else
    #error You must install New LiquidCrystal library to work with non-4bit projects: http:/bitbucket.org/fmalpartida/new-liquidcrystal/wiki/Home
  #endif
#endif

// library interface description
class BigFont {
  public:
    // constructor:
    BigFont(uint8_t size = 3);

    // load special characters
    #ifndef LiquidCrystal_I2C_h // New liquid crystal library
    void loadchars(LiquidCrystal& lcd);
    #else
    void loadchars(LiquidCrystal_I2C& lcd);
    #endif

    // print char method
    #ifndef LiquidCrystal_I2C_h // New liquid crystal library
    void printblankchar(LiquidCrystal& lcd, byte col, byte row);
    void printbigchar(LiquidCrystal& lcd, byte digit, byte col, byte row);
    #else
    void printblankchar(LiquidCrystal_I2C& lcd, byte col, byte row);
    void printbigchar(LiquidCrystal_I2C& lcd, byte digit, byte col, byte row);
    #endif

    uint8_t getFontSize();
    void setFontSize(uint8_t size);

    int version(void);

  private:
    uint8_t _fontSize;
    // Define the custom characters parts
    // The order is 1,2,3 for curved top, 4,5,6 for curved bottom
    // 0 is used for number 4, 7 is the alarm bell symbol
    // parts for 3x2 bigfont
    // byte custchar2[8][8] =
    byte custchar2[7][8] =
    {
      { // 0
          B00000,
          B00000,
          B00000,
          B00000,
          B00000,
          B11111,
          B11111,
          B11111
        },
        { // 1
          B00111,
          B01111,
          B11111,
          B11111,
          B11111,
          B11111,
          B11111,
          B11111
        },
        { // 2
          B11111,
          B11111,
          B11111,
          B00000,
          B00000,
          B00000,
          B00000,
          B00000
        },
        { // 3
          B11100,
          B11110,
          B11111,
          B11111,
          B11111,
          B11111,
          B11110,
          B11100
        },
        { // 4
          B11111,
          B11111,
          B11111,
          B11111,
          B11111,
          B11111,
          B01111,
          B00111
        },
        { // 5
          B11111,
          B00000,
          B00000,
          B00000,
          B00000,
          B00000,
          B00000,
          B11111
        },
        { // 6
          B11111,
          B11111,
          B11111,
          B11111,
          B11111,
          B11111,
          B11110,
          B11100
        }/*,
        { // 7 (alarm symbol) same for all fonts, defined below
          B00100,
          B01110,
          B01110,
          B01110,
          B11111,
          B00000,
          B00100,
          B00000
        }*/
    }; // custchar[]
    // custchar (3x3, 4x4)
    byte custchar3[8][8] =
    {
      { // 0 // slash used for number 4
          B00001,
          B00011,
          B00111,
          B01111,
          B11111,
          B11110,
          B11100,
          B11000
        },
        { // 1
          B00111,
          B01111,
          B11111,
          B11111,
          B11111,
          B11111,
          B11111,
          B11111
        },
        { // 2
          B11111,
          B11111,
          B11111,
          B00000,
          B00000,
          B00000,
          B00000,
          B00000
        },
        { // 3
          B11100,
          B11110,
          B11111,
          B11111,
          B11111,
          B11111,
          B11111,
          B11111
        },
        { // 4
          B11111,
          B11111,
          B11111,
          B11111,
          B11111,
          B11111,
          B01111,
          B00111
        },
        { // 5
          B00000,
          B00000,
          B00000,
          B00000,
          B00000,
          B11111,
          B11111,
          B11111
        },
        { // 6
          B11111,
          B11111,
          B11111,
          B11111,
          B11111,
          B11111,
          B11110,
          B11100
        },
        { // 7 (alarm symbol)
          B00100,
          B01110,
          B01110,
          B01110,
          B11111,
          B00000,
          B00100,
          B00000
        }
    }; // custchar[]
   // Define the large fonts, borrowed from GreenHerron RT-21 pictures
   // Define here globally for Class so not define on each call to print character
   // FONTS 4x4
   	byte bignums[10][4][4] =
   	{
   	  { // 0
   	{  1,   2,   2,   3},
   	{255, 254, 254, 255},
   	{255, 254, 254, 255},
   	{  4,   5,   5,   6}
   	  },
   	  { // 1
   	{254,   1, 255, 254},
   	{254, 254, 255, 254},
   	{254, 254, 255, 254},
   	{254,   5, 255,   5}
   	  },
   	  { // 2
   	{  1,   2,   2,   3},
   	{254, 254,   5,   6},
   	{  1,   2, 254, 254},
   	{255,   5,   5,   5}
   	  },
   	  { // 3
   	{  1,   2,   2,   3},
   	{254, 254,   5,   6},
   	{254, 254,   2,   3},
   	{  4,   5,   5,   6}
   	  },
   	  { // 4
   	{255, 254, 254, 255},
   	{255, 254, 254, 255},
   	{  4,   5,   5, 255},
   	{254, 254, 254, 255}
   	  },
   	  { // 5
   	{255,   2,   2,   2},
   	{  2,   2,   2,   3},
   	{254, 254, 254, 255},
   	{  4,   5,   5,   6}
   	  },
   	  { // 6
   	{  1,   2,   2, 254},
   	{255,   2,   2,   3},
   	{255, 254, 254, 255},
   	{  4,   5,   5,   6}
   	  },
   	  { // 7
   	{  4,   2,   2, 255},
   	{254, 254,   1,   6},
   	{254, 254, 255, 254},
   	{254, 254, 255, 254}
   	  },
   	  { // 8
   	{  1,   2,   2,   3},
   	{  4,   5,   5,   6},
   	{  1,   2,   2,   3},
   	{  4,   5,   5,   6}
   	  },
   	  { // 9
   	{  1,   2,   2,   3},
   	{255, 254, 254, 255},
   	{  4,   5,   5, 255},
   	{254,   5,   5,   6}
   	  }
   	}; // bignums[]

   	// FONTS 3x3
   	byte bignums3x3[10][3][3] =
   	{
   	  { // 0
   	{  1,   2,   3},
   	{255, 254, 255},
   	{  4,   5,   6},
   	  },
   	  { // 1
   	{  0, 255, 254},
   	{254, 255, 254},
   	{  5, 255,   5},
   	  },
   	  { // 2
   	{  1,   2,   3},
   	{254,   5,   6},
   	{  1,   5,   5},
   	  },
   	  { // 3
   	{  1,   2,   3},
   	{254,   2,   3},
   	{  4,   5,   6},
   	  },
   	  { // 4
   	{254,   0, 255},
   	{  1,   5,   6},
   	{254, 254,   3},
   	  },
   	  { // 5
   	{255,   2,   2},
   	{  2,   2,   3},
   	{  5,   5,   6},
   	  },
   	  { // 6
   	{  1,   2, 254},
   	{255,   2,   3},
   	{  4,   5,   6},
   	  },
   	  { // 7
   	{  4,   2, 255},
   	{254,   1,   6},
   	{254, 255, 254},
   	  },
   	  { // 8
   	{  1,   2,   3},
   	{  1,   2,   3},
   	{  4,   5,   6},
   	  },
   	  { // 9
   	{  1,   2,   3},
   	{  4,   5, 255},
   	{  4,   5,   6},
   	  }
   	}; // bignums3x3[]

   // FONTS 3x2
   // 	byte bignums3x2[10][3][3] =
   byte bignums3x2[10][2][3] =
   	{
   	  { // 0
   	{  1,   2, 255},
   	{  4,   0,   6}
   	  },
   	  { // 1
   	{ 47, 255, 254},
   	{254, 255, 254}
   	  },
   	  { // 2
    {  2,   5,   3},
   	{  1,   5,   0},
   	  },
   	  { // 3
   	{  2,   5,   3},
   	{  0,   5,   3}
   	  },
   	  { // 4
   	{  1, 254, 255},
   	{254,   2,   6}
   	  },
   	  { // 5
   	{255,   5,   2},
   	{  0,   5,   3}
   	  },
   	  { // 6
   	{  1,   2, 254},
   	{  4,   5,   3}
   	  },
   	  { // 7
   	{  4,   2,   6},
   	{254,  47, 254}
   	  },
   	  { // 8
   	{  1,   5,   3},
   	{  1,   5,   3}
   	  },
   	  { // 9
   	{  1,   2, 255},
   	{  0,   5,   6}
   	  }
   	}; // bignums3x2[]
}; // Class BigFont
#endif
