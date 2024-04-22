#pragma once


// The respective setup() function for implementing all the LEDs
void LEDSetup() {
  for (int i = 0; i < LEDsPerColumn; i++) {
    pinMode(rLEDs[i], OUTPUT);
    pinMode(gLEDs[i], OUTPUT);
    pinMode(yLEDs[i], OUTPUT);
    pinMode(cLEDs[i], OUTPUT);
  }
}


void turnAllOff() {
  for (int i = 0; i < LEDsPerColumn; i++) {
    digitalWrite(rLEDs[i], LOW);
    digitalWrite(gLEDs[i], LOW);
    digitalWrite(yLEDs[i], LOW);
    digitalWrite(cLEDs[i], LOW);
  }
}

void turnAllOn() {
  for (int i = 0; i < LEDsPerColumn; i++) {
    digitalWrite(rLEDs[i], HIGH);
    digitalWrite(gLEDs[i], HIGH);
    digitalWrite(yLEDs[i], HIGH);
    digitalWrite(cLEDs[i], HIGH);
  }
}

void rainTestLoop() {
  int i = LEDsPerColumn;
  while (i >= 0) {
    digitalWrite(rLEDs[i-3], HIGH);
    digitalWrite(gLEDs[i-3], HIGH);
    digitalWrite(yLEDs[i-3], HIGH);
    digitalWrite(cLEDs[i-3], HIGH);

    digitalWrite(rLEDs[i-4], LOW);
    digitalWrite(gLEDs[i-4], LOW);
    digitalWrite(yLEDs[i-4], LOW);
    digitalWrite(cLEDs[i-4], LOW);

    // Delay time between
    delay(1000);
  }
}


// All LEDs flash simultaneously on and off
void allFlashTest() {
  turnAllOn();
  delay(1000);
  turnAllOff();
  delay(1000);
}
