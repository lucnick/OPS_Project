



void setup() {
  // Init Pins
  pinMode(B1, INPUT);
  pinMode(B2, INPUT);
  pinMode(B3, INPUT);
  pinMode(B4, INPUT);
  pinMode(B5, INPUT);
  pinMode(B6, INPUT);
  pinMode(B7, INPUT);
  pinMode(B8, INPUT);

  pinMode(rLED, INPUT);
  pinMode(gLED, INPUT);
  pinMode(yLED, INPUT);
  pinMode(cLED, INPUT);

  Serial.begin(9600);
  
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Dance Dance");
  lcd.setCursor(0,1);
  lcd.print("Revolution");
  delay(start_delay);
  lcd.clear();

  // Print a message to the LCD.
  lcd.print("P1   P2   Time");
}

void loop() {
  // Gameplay Code
  if (((millis() / 1000) - time_reference) > (LED_SPEED-0.1)){
    // Updates Player 1
    if((digitalRead(B1) == HIGH) && (digitalRead(rLED) == HIGH)){
      score1++;
      time_reference = (millis() / 1000);
    }
    else if((digitalRead(B2) == HIGH) && (digitalRead(gLED) == HIGH)){
      score1++;
      time_reference = (millis() / 1000);
    }
    else if((digitalRead(B3) == HIGH) && (digitalRead(yLED) == HIGH)){
      score1++;
      time_reference = (millis() / 1000);
    }
    else if((digitalRead(B4) == HIGH) && (digitalRead(cLED) == HIGH)){
      score1++;
      time_reference = (millis() / 1000);
    }
    else if((digitalRead(B1) == HIGH) || (digitalRead(B2) == HIGH) || (digitalRead(B3) == HIGH) || (digitalRead(B4) == HIGH)){
      if (score1 >= 1) {
        score1--;
      }
      time_reference = (millis() / 1000);
    }

    // Update Player 2
    if((digitalRead(B5) == HIGH) && (digitalRead(rLED) == HIGH)){
      score2++;
      time_reference = (millis() / 1000);
    }
    else if((digitalRead(B6) == HIGH) && (digitalRead(gLED) == HIGH)){
      score2++;
      time_reference = (millis() / 1000);
    }
    else if((digitalRead(B7) == HIGH) && (digitalRead(yLED) == HIGH)){
      score2++;
      time_reference = (millis() / 1000);
    }
    else if((digitalRead(B8) == HIGH) && (digitalRead(cLED) == HIGH)){
      score2++;
      time_reference = (millis() / 1000);
    }
    else if((digitalRead(B5) == HIGH) || (digitalRead(B6) == HIGH) || (digitalRead(B7) == HIGH) || (digitalRead(B8) == HIGH)) {
      if (score2 >= 1) {
        score2--;
      }
      time_reference = (millis() / 1000);
    }
  } 

  
  // Counter Logic
  sec = (((millis() - start_delay)/1000))%10;
  sec_tens = (((millis() - start_delay)/10000))%10;
  min = (((millis() - start_delay)/60000))%60;
  if (min == 1){
    sec = 0;
    sec_tens = 0;
  }  
  // Projects Counter onto Screen
  lcd.setCursor(10, 1);
  lcd.print(min);
  lcd.setCursor(11, 1);
  lcd.print(":");
  lcd.setCursor(12,1);
  lcd.print(sec_tens);
  lcd.setCursor(13,1);
  lcd.print(sec);
  
  // Prints Player Scores
  lcd.setCursor(0, 1);
  lcd.print(score1); // Player 1
  lcd.setCursor(5,1);
  lcd.print(score2); // Player 2

  // End of Game Check
  int elapsed = millis() / 1000;
  int check = 60 + (start_delay/1000);
  Serial.print("Elapsed:");
  Serial.println(elapsed);

  Serial.print("Check:");
  Serial.println(check);

  if ((elapsed) > (check)){
    lcd.clear();
    if (score1 > score2){
      lcd.setCursor(0,0); // Player Win
      lcd.print("Player 1 Wins!");
      lcd.setCursor(0,1); // Score:
      lcd.print("Score:");
      lcd.setCursor(7,1); // Actual score
      lcd.print(score1);
    }
    else{
      lcd.setCursor(0,0); // Player Win
      lcd.print("Player 2 Wins!");
      lcd.setCursor(0,1); // Score:
      lcd.print("Score:");
      lcd.setCursor(7,1); // Actual score
      lcd.print(score2);
    }
    gameEnded();
  }
}

void gameEnded(){
  while(true){
    Serial.println("Game ended!");
  }
}
