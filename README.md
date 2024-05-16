# Project Overview
Dance dance revolution implemented with Arduino Nanos.
First Prize Winner for the OPS Capstone Project (UF IEEE Student Branch).

Collaborators: Nicholas Lucindo, Landon Amaba, Carter Amaba.

## Arduino Structure

Arduino 1 controls the LEDs, randomization sequences, and digital output pins to communicate signals to Arduino 2.

Arduino 2 controls the LCD screen displaying scores, button logic, the timer, and game-end logic.

Arduino 3 controls the music, where the song can be selected using a potentiometer on its own respective board.

## File Structure
The outermost directory contains three folders: "Arduino 1, Arduino 2, Arduino 3."

Each of these directories has a ".ino" file. This is the file that should be opened in the Arduino IDE and pushed to the corresponding Arduino.

The "Definitions.h" file for each Arduino handles pin definitions and other constants.

