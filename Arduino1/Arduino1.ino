
#include "Definitions.h"
#include "Randomizer.h"
#include "Tests.h"
#include "Game.h"


void setup() {


  Serial.begin(9600); // Prepare to SEND the current color

  LEDSetup(); // Set up LED Definitions
}

void loop() {

  
  GameLEDs();

}


