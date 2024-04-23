#pragma once


void customSwap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void shuffleColors(char arr[], unsigned int seed) {
    for (int i = 0; i < 3; i++) {
        int j = getRandom(4, seed);
        customSwap(&arr[i], &arr[j]);
    }
}


void GameLEDs() {

  int numColors = 4;
  char colors[7] = {'r','g','y','c','n','n','n'};
  
  shuffleColors(colors, seed);

  int rCount = 0;
  int gCount = 0;
  int yCount = 0;
  int cCount = 0;
  int nCount = 0;

  bool rStarted = false;
  bool gStarted = false;
  bool yStarted = false;
  bool cStarted = false;


  for (int i = 0; i < numColors + 3; i++) {
    
    if (rCount > 3)
      rStarted = false;
    if (gCount > 3)
      gStarted = false;
    if (yCount > 3)
      yStarted = false;
    if (cCount > 3)
      cStarted = false;
    
    // Conditionals for cycling LEDs downwards
    if (colors[i % 7] == 'r' || rStarted == true) {
      digitalWrite(rLEDs[rCount], HIGH);
      digitalWrite(rLEDs[rCount-1], LOW);
      digitalWrite(rLEDs[rCount-2], LOW);
      rCount++;
      rStarted = true;
    }
    if (colors[i % 7] == 'g' || gStarted == true) {
      digitalWrite(gLEDs[gCount], HIGH);
      digitalWrite(gLEDs[gCount-1], LOW);
      digitalWrite(gLEDs[gCount-2], LOW);
      gCount++;
      gStarted = true;
    }
    if (colors[i % 7] == 'y' || yStarted == true) {
      digitalWrite(yLEDs[yCount], HIGH);
      digitalWrite(yLEDs[yCount-1], LOW);
      digitalWrite(yLEDs[yCount-2], LOW);
      yCount++;
      yStarted = true;
    }
    if (colors[i % 7] == 'c' || cStarted == true) {
      digitalWrite(cLEDs[cCount], HIGH);
      digitalWrite(cLEDs[cCount-1], LOW);
      digitalWrite(cLEDs[cCount-2], LOW);
      cCount++;
      cStarted = true;
    }

    // Handles edge case glitch where multiple LEDs light up
    if (i % 7 == 3) {
      if (colors[i % 7] != 'r')
        digitalWrite(rLEDs[0], LOW);
      if (colors[i % 7] != 'y')
        digitalWrite(yLEDs[0], LOW);
      if (colors[i % 7] != 'g')
        digitalWrite(gLEDs[0], LOW);
      if (colors[i % 7] != 'c')
        digitalWrite(cLEDs[0], LOW);
    }


    if (colors[i % 7] == 'n') {
      digitalWrite(rLEDs[0], LOW);
      digitalWrite(gLEDs[0], LOW);
      digitalWrite(yLEDs[0], LOW);
      digitalWrite(cLEDs[0], LOW);
    }



    delay(1000);
    
  }
  turnAllOff();
}

