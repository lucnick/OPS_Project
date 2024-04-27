 #pragma once

 /* 
 LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
The LCD circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 */


#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int sec = 0;
int min = 0;
int sec_tens = 0;
int start_delay = 3000; // Start_Delay in Seconds
int score1 = 0;
int score2 = 0;
int time_reference;
int LED_SPEED = 1; // LED will stay on for 1 second (Will change as game progresses)

#define B1 A0
#define B2 A1
#define B3 A2
#define B4 A3
#define B5 A4
#define B6 A5
#define B7 6
#define B8 13

#define rLED 10
#define gLED 9
#define yLED 8
#define cLED 7
