
#include "Definitions.h"
#include "Randomizer.h"
#include "Tests.h"
#include "Game.h"


void setup() {

  Serial.begin(9600); // Prepare to SEND the current color

  LEDSetup(); // Set up LED Definitions
}


void terminate() {
  StartupLEDs();
  while (true) {
    Serial.println("Done!");
  }
}




int gameTime = 60000;   // 60 seconds
int start_delay = 3000;

void loop() {

  StartupLEDs();

  while (true) {

  int elapsed = millis() / 1000;
  int check = 60 + (start_delay/1000);
  Serial.print("Elapsed:");
  Serial.println(elapsed);
  
  if ((elapsed) > (check))
    terminate();

    GameLEDs();
    seed += 7;
    Serial.println(millis());
  }
  terminate();
}




