#pragma once

void shuffleColors(char arr[], int numColors) {
    for (int i = numColors - 1; i > 0; i--) {
      int j = getRandomIndex(i + 1);
      char temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
  }
}






void GameLEDs() {

  int numColors = 4;
  char colors[4] = {'r','g','y','c'};

  int rCount = 0;
  int gCount = 0;
  int yCount = 0;
  int cCount = 0;
  int nCount = 0;

  bool rStarted = false;
  bool gStarted = false;
  bool yStarted = false;
  bool cStarted = false;


  // shuffleColors(colors, numColors);

  for (int i = 0; i < numColors + 3; i++) {
    
    // Conditionals for cycling LEDs downwards
    if (colors[i] == 'r' || rStarted == true) {
      digitalWrite(rLEDs[rCount], HIGH);
      digitalWrite(rLEDs[rCount-1], LOW);
      rCount++;
      rStarted = true;
    }
    if (colors[i] == 'g' || gStarted == true) {
      digitalWrite(gLEDs[gCount], HIGH);
      digitalWrite(gLEDs[gCount-1], LOW);
      gCount++;
      gStarted = true;
    }
    if (colors[i] == 'y' || yStarted == true) {
      digitalWrite(yLEDs[yCount], HIGH);
      digitalWrite(yLEDs[yCount-1], LOW);
      yCount++;
      yStarted = true;
    }
    if (colors[i] == 'c' || cStarted == true) {
      digitalWrite(cLEDs[cCount], HIGH);
      digitalWrite(cLEDs[cCount-1], LOW);
      cCount++;
      cStarted = true;
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

