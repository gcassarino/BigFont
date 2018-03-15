# BigFont Library for Arduino

This library allows a board to display big digits/numbers on 4 row monochrome text displays.

This library is derived from [https://github.com/wa1hco/BigFont](https://github.com/wa1hco/BigFont) but unlike the previous this library implements multiple font sizes: 3x2, 3x3 and 4x4 fonts


## Getting Started

This library was tested using a LCD display drived by the Hitachi HD44780 LCD controller. The controller was drived using the [New LiquidCrystal](https://bitbucket.org/fmalpartida/new-liquidcrystal/wiki/Home) LCD Library from Francisco Malpartida. 

Example of use:
```
    BigFont bigfont(3); // declaration, 2 for 3colx2rows, 3 for 3colx3rows or 4 4colx4rows digits
    
    bigfont.setFontSize(size); // used to change display font size 2,3 or 4

    	if(_bigFontSize == 2){
		bigfont.printbigchar(lcd, 0, 0, 0);
		bigfont.printbigchar(lcd, this->_dt.hour, 3, 0);
	} else if(_bigFontSize == 3){
		bigfont.printbigchar(lcd, 0, 0, 0);
		bigfont.printbigchar(lcd, this->_dt.hour, 3, 0);
	} else {
		bigfont.printbigchar(lcd, 0, 0, 0);
		bigfont.printbigchar(lcd, this->_dt.hour, 4, 0);
	}

```
The BigFont library was tested on ESP8266 and ATMega328 boards using the Arduino core.


## Authors

* Tom Igoe et al... - *Initial work*
* [wa1hco](https://github.com/wa1hco/BigFont)
* [Gianluca Cassarino](https://github.com/gcassarino) - this version for LCD displays


## License

This project is licensed under the GPL License - see the [LICENSE](LICENSE) file for details

## Acknowledgments/Credits

* this Library is derived from [wa1hco BigFont](https://github.com/wa1hco/BigFont) 
* BigFont.cpp - Big Font library for Arduino - Version 0.1 Derived from Stepper.cpp Original library (0.1) by Tom Igoe et al...
* [Francisco Malpartida](https://bitbucket.org/fmalpartida/) for writing the excellent library New LiquidCrystal

