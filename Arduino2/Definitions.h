#pragma once

// File containing all pin definitions for Arduino #1
// This is the arduino controlling the LEDs, implemented on the breadboard itself

#define R0 A3
#define R1 A4
#define R2 A5

#define G0 A2
#define G1 A1
#define G2 A0

#define Y0 10
#define Y1 9
#define Y2 7

#define C0 11
#define C1 12
#define C2 5

// Indexable definitions (Array form)
const int LEDsPerColumn = 3;
int rLEDs[] = {R0, R1, R2};
int gLEDs[] = {G0, G1, G2};
int yLEDs[] = {Y0, Y1, Y2};
int cLEDs[] = {C0, C1, C2};
