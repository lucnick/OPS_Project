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



// ALL ON AND OFF FUNCTIONS:
void rOff() {
  for (int i = 0; i < LEDsPerColumn; i++) {
    digitalWrite(rLEDs[i], LOW);
  }
}
void gOff() {
  for (int i = 0; i < LEDsPerColumn; i++) {
    digitalWrite(gLEDs[i], LOW);
  }
}
void yOff() {
  for (int i = 0; i < LEDsPerColumn; i++) {
    digitalWrite(yLEDs[i], LOW);
  }
}
void cOff() {
  for (int i = 0; i < LEDsPerColumn; i++) {
    digitalWrite(cLEDs[i], LOW);
  }
}
void rOn() {
  for (int i = 0; i < LEDsPerColumn; i++) {
    digitalWrite(rLEDs[i], HIGH);
  }
}
void gOn() {
  for (int i = 0; i < LEDsPerColumn; i++) {
    digitalWrite(gLEDs[i], HIGH);
  }
}
void yOn() {
  for (int i = 0; i < LEDsPerColumn; i++) {
    digitalWrite(yLEDs[i], HIGH);
  }
}
void cOn() {
  for (int i = 0; i < LEDsPerColumn; i++) {
    digitalWrite(cLEDs[i], HIGH);
  }
}

// Turns off all LEDs
void turnAllOff() {
  rOff();
  gOff();
  yOff();
  cOff();
}

// Turns on all LEDs
void turnAllOn() {
  rOn();
  gOn();
  yOn();
  cOn();
}


void cycleAcross(int totalTime) {

  int delayTime = totalTime / 5;
  rOn();
  delay(delayTime);
  rOff();
  gOn();
  delay(delayTime);
  gOff();
  yOn();
  delay(delayTime);
  yOff();
  cOn();
  delay(delayTime);
  cOff();
  delay(delayTime);
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
void allFlashTest(int delayTime) {
  turnAllOn();
  delay(delayTime);
  turnAllOff();
  delay(delayTime);
}


// Total 3000 ms
void StartupLEDs() {

  cycleAcross(2000);  // 2000 ms
  turnAllOff();
  allFlashTest(200);  // 400 ms
  turnAllOff();
  allFlashTest(200);  // 400 ms
  turnAllOff();
  delay(600);         // 600 ms         
}


