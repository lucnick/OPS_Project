#pragma once


void customSwap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void shuffleColors(char arr[], unsigned int seed) {
    for (int i = 0; i < 3; i++) {
        int j = getRandom(4, &seed);
        customSwap(&arr[i], &arr[j]);
    }
}


void GameLEDs() {

  int numColors = 4;
  char colors[7] = {'r','g','y','c','n','n','n'};
  
  shuffleColors(colors, getRandomSeed());

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
    
    // Conditionals for cycling LEDs downwards
    if (colors[i % 7] == 'r' || rStarted == true) {
      digitalWrite(rLEDs[rCount], HIGH);
      digitalWrite(rLEDs[rCount-1], LOW);
      rCount++;
      rStarted = true;
    }
    if (colors[i % 7] == 'g' || gStarted == true) {
      digitalWrite(gLEDs[gCount], HIGH);
      digitalWrite(gLEDs[gCount-1], LOW);
      gCount++;
      gStarted = true;
    }
    if (colors[i % 7] == 'y' || yStarted == true) {
      digitalWrite(yLEDs[yCount], HIGH);
      digitalWrite(yLEDs[yCount-1], LOW);
      yCount++;
      yStarted = true;
    }
    if (colors[i % 7] == 'c' || cStarted == true) {
      digitalWrite(cLEDs[cCount], HIGH);
      digitalWrite(cLEDs[cCount-1], LOW);
      cCount++;
      cStarted = true;
    }

    if (colors[i % 7] == 'n') {
      digitalWrite(rLEDs[0], LOW);
      digitalWrite(gLEDs[0], LOW);
      digitalWrite(yLEDs[0], LOW);
      digitalWrite(cLEDs[0], LOW);
    }

    if (rCount > 3)
      rOff();
    if (gCount > 3)
      gOff();
    if (yCount > 3)
      yOff();
    if (cCount > 3)
      cOff();

    delay(1000);
    
  }
  rOff();
  gOff();
  yOff();
  cOff();
}

