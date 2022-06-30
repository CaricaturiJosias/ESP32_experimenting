/*
 * Using LCD screen with ESP32 
 * Written by Ahmad Shamshiri on Sep 04, 2019
 * at 17:49 in Ajax, Ontario, Canada
 * for Robojax.com
 * Watch video instruction for this code: 
 https://youtu.be/COssWn4Pcm4
 * 
Get this code and other Arduono codes from Robojax.com
You can get the wiring diagram from my Arduino Course at Udemy.com
Learn Arduino step by step with all library, codes, wiring diagram all in one place
visit my course now http://robojax.com/L/?id=62

If you found this tutorial helpful, please support me so I can continue creating 
content like this. You can support me on Patreon http://robojax.com/L/?id=63
or make donation using PayPal http://robojax.com/L/?id=64

 * Code is available at http://robojax.com/learn/arduino
 * This code is "AS IS" without warranty or liability. Free to be used as long as you keep this note intact.* 
 * This code has been download from Robojax.com
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>. 

*/

// start of settings for LCD1602 with I2C
#include <LiquidCrystal.h>
#include <Arduino.h>
 
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(19, 23, 18, 17, 16, 22);
int ADC_VALUE = 0;
int bits = 4095;
float Max_tension = 5;
double voltage_value = 0;
const int Analog_channel_pin= 15;
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("A measure:");

  Serial.begin(9600);
  analogSetAttenuation(ADC_11db);
  pinMode(Analog_channel_pin, ANALOG);
}
 
void loop() {
  ADC_VALUE = analogRead(Analog_channel_pin);
  voltage_value = (ADC_VALUE * Max_tension ) / (bits);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(voltage_value);
}