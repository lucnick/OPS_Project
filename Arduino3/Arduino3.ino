// import note constants
#include "pitches.h"

// DEFINING PINS
#define SPEAKER 2  // speaker output (uses PWM)
#define song1_pin 12
#define song2_pin 7
#define song3_pin 4
#define POT A6  // potentiometer

int NOTE_DUR = 137;  // duration of each note


void setup() {
  // initial pin setup
  pinMode(SPEAKER, OUTPUT);
  pinMode(song1_pin, OUTPUT);
  pinMode(song2_pin, OUTPUT);
  pinMode(song3_pin, OUTPUT);
  pinMode(POT, INPUT);
  Serial.begin(9600);
}

void play(int note, int dur) {
  tone(SPEAKER, note);
  delay(dur * NOTE_DUR);
  noTone(SPEAKER);
  delay(dur * NOTE_DUR / 3);
}





// GRAVITY FALLS OPENING
void song3() {
  // Reset other two LEDs to low
  digitalWrite(song1_pin, LOW);
  digitalWrite(song2_pin, LOW);
  digitalWrite(song3_pin, HIGH);

  NOTE_DUR = 55;

  play(NOTE_F4, 8);
  play(NOTE_E4, 8);

  play(NOTE_G4, 8);
  play(NOTE_A5, 8);

  play(NOTE_G4, 8);
  play(NOTE_F4, 8);

  delay(4 * NOTE_DUR);
  play(NOTE_F4, 4);
  play(NOTE_F4, 4);
  play(NOTE_F4, 4);

  play(NOTE_A5, 4);
  play(NOTE_A5, 4);
  play(NOTE_G4, 4);
  play(NOTE_F4, 4);

  delay(4 * NOTE_DUR);
  play(NOTE_A5, 4);
  play(NOTE_A5, 4);
  play(NOTE_A5, 4);

  play(NOTE_G4, 4);
  play(NOTE_A5, 4);
  play(NOTE_G4, 4);
  play(NOTE_F4, 4);

  // 3 measures repeat
  delay(4 * NOTE_DUR);
  play(NOTE_F4, 4);
  play(NOTE_F4, 4);
  play(NOTE_F4, 4);

  play(NOTE_A5, 4);
  play(NOTE_A5, 4);
  play(NOTE_G4, 4);
  play(NOTE_F4, 4);

  delay(4 * NOTE_DUR);
  play(NOTE_A5, 4);
  play(NOTE_A5, 4);
  play(NOTE_A5, 4);

  // sharp in the middle
  delay(4 * NOTE_DUR);
  play(NOTE_CS5, 4);
  play(NOTE_CS5, 4);
  play(NOTE_CS5, 4);

  // repeat again
  delay(4 * NOTE_DUR);
  play(NOTE_F4, 4);
  play(NOTE_F4, 4);
  play(NOTE_F4, 4);

  play(NOTE_A5, 4);
  play(NOTE_A5, 4);
  play(NOTE_G4, 4);
  play(NOTE_F4, 4);

  delay(4 * NOTE_DUR);
  play(NOTE_A5, 4);
  play(NOTE_A5, 4);
  play(NOTE_A5, 4);

  // alternate ending
  play(NOTE_G4, 8);
  play(NOTE_C5, 8);
  play(NOTE_A5, 8);
  play(NOTE_CS5, 8);
  delay(8 * NOTE_DUR);

  // final sharp notes and ending "neow"
  play(NOTE_F4, 2);
  play(NOTE_D4, 2);
  play(NOTE_F4, 2);
  play(NOTE_A5, 2);

  play(NOTE_E4, 2);
  play(NOTE_CS4, 2);
  play(NOTE_A5, 2);
  play(NOTE_CS5, 2);

  play(NOTE_D5, 16);
  delay(8 * NOTE_DUR);

}


#define NOTE_DUR 250 // Define the default note duration


// Function to play the melody of "Boom Boom Dollar"
void boomBoomDollar() {
  // Define the notes and durations of the melody
  int melody[] = {
    NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5,
    NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5,
    NOTE_D5, NOTE_DS5, NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_FS5, NOTE_G5, NOTE_FS5,
    NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_FS5, NOTE_G5, NOTE_FS5,
    NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5,
    NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5,
    NOTE_D5, NOTE_DS5, NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_FS5, NOTE_G5, NOTE_FS5,
    NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_FS5, NOTE_G5, NOTE_FS5
  };
 
  // Define the note durations (1 = quarter note, 0.5 = eighth note, etc.)
  float noteDurations[] = {
    0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
    0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
    1.0, 0.5, 0.5, 1.0, 0.5, 0.5, 1.0, 0.5,
    0.5, 0.5, 0.5, 1.0, 0.5, 0.5, 1.0, 0.5,
    0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
    0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
    1.0, 0.5, 0.5, 1.0, 0.5, 0.5, 1.0, 0.5,
    0.5, 0.5, 0.5, 1.0, 0.5, 0.5, 1.0, 0.5
  };


  // Calculate the length of the arrays
  int length = sizeof(melody) / sizeof(melody[0]);


  // Iterate over the melody and play each note
  for (int i = 0; i < length; i++) {
    int noteDuration = NOTE_DUR * noteDurations[i]; // Calculate note duration
    tone(SPEAKER, melody[i], noteDuration); // Play the note
    delay(noteDuration * 1.1); // Delay between notes (slightly longer than the note duration)
    noTone(SPEAKER); // Stop the tone
    delay(NOTE_DUR / 2); // Short delay between notes
  }
}


// Function to play the melody of "HIGHS OFF U (Scorccio XY Mix)"
void highsOffU() {
  // Define the notes and durations of the melody
  int melody[] = {
    NOTE_F5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_D5, NOTE_F5, NOTE_D5,
    NOTE_D5, NOTE_C5, NOTE_D5, NOTE_D5, NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_F5,
    NOTE_E5, NOTE_D5, NOTE_E5, NOTE_FS5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_F5,
    NOTE_D5, NOTE_C5, NOTE_A5, NOTE_F5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_FS5,
    NOTE_G5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_D5, NOTE_C5, NOTE_A5, NOTE_F5,
    NOTE_D5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5,
    NOTE_D5, NOTE_E5, NOTE_FS5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_D5,
    NOTE_C5, NOTE_A5, NOTE_F5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_FS5, NOTE_G5
  };


  // Define the note durations (1 = quarter note, 0.5 = eighth note, etc.)
  float noteDurations[] = {
    0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25,
    0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25,
    0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25,
    0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25,
    0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25,
    0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25,
    0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25,
    0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25
  };


  // Calculate the length of the arrays
  int length = sizeof(melody) / sizeof(melody[0]);


  // Iterate over the melody and play each note
  for (int i = 0; i < length; i++) {
    int noteDuration = NOTE_DUR * noteDurations[i]; // Calculate note duration
    tone(SPEAKER, melody[i], noteDuration); // Play the note
    delay(noteDuration * 1.1); // Delay between notes (slightly longer than the note duration)
    noTone(SPEAKER); // Stop the tone
    delay(NOTE_DUR / 2); // Short delay between notes
  }
}


void terminate() {
  while (true) {
    Serial.println("Done");
  }
}


bool firstIteration = true;
int startDelay = 3000;

void loop() {

  if (firstIteration)
    delay(startDelay);
  else
    firstIteration = false;

  if (millis() > startDelay + 60000) {
    terminate();
  }
  int POT_value = analogRead(POT);
  
  Serial.println(POT_value);

  // Play different song based on potentiometer input
  if (POT_value < 341) {
    boomBoomDollar();

  } else if (POT_value < 682) {
    highsOffU();
  
  } else {
    song3();
  }
  
}


// EXTRA SONGS
/*
// JINGLE BELLS
void song1() {

  // Reset other two LEDs to low
  digitalWrite(song2_pin, LOW);
  digitalWrite(song3_pin, LOW);
  digitalWrite(song1_pin, HIGH);  // turn on LED 2
  
  NOTE_DUR = (7500/30);
  play(NOTE_E4, 1); 
  play(NOTE_E4, 1);
  play(NOTE_E4, 2);
  play(NOTE_E4, 1);
  play(NOTE_E4, 1);
  play(NOTE_E4, 2);
  play(NOTE_E4, 1); 
  play(NOTE_G4, 1);
  play(NOTE_C4, 1.5);
  play(NOTE_D4, 0.5);
  play(NOTE_E4, 4); 
  play(NOTE_F4, 1);
  play(NOTE_F4, 1.5);
  play(NOTE_F4, 0.5);
  play(NOTE_F4, 1);
  play(NOTE_E4, 1);
  play(NOTE_E4, 1);
  play(NOTE_E4, 0.5);
  play(NOTE_E4, 0.5);
  play(NOTE_E4, 1); 
  play(NOTE_D4, 1);
  play(NOTE_D4, 1);
  play(NOTE_E4, 1);
  play(NOTE_D4, 2);
  play(NOTE_G4, 2);

  play(NOTE_E4, 1); 
  play(NOTE_E4, 1);
  play(NOTE_E4, 2);
  play(NOTE_E4, 1);
  play(NOTE_E4, 1);
  play(NOTE_E4, 2);
  play(NOTE_E4, 1); 
  play(NOTE_G4, 1);
  play(NOTE_C4, 1.5);
  play(NOTE_D4, 0.5);
  play(NOTE_E4, 4);
  play(NOTE_F4, 1);
  play(NOTE_F4, 1.5);
  play(NOTE_F4, 0.5);
  play(NOTE_F4, 1);
  play(NOTE_E4, 1);
  play(NOTE_E4, 1);
  play(NOTE_E4, 0.5);
  play(NOTE_E4, 0.5);
  play(NOTE_E4, 1);
  play(NOTE_D4, 1);
  play(NOTE_D4, 1);
  play(NOTE_E4, 1);
  play(NOTE_D4, 2);
  play(NOTE_G4, 2);

  delay(8 * NOTE_DUR); // ending delay
}

// FORTNITE DEFAULT DANCE
void song2() {
  // Reset other two LEDs to low
  digitalWrite(song1_pin, LOW);
  digitalWrite(song3_pin, LOW);
  digitalWrite(song2_pin, HIGH);  // turn on LED 2

  NOTE_DUR = 120;
  play(NOTE_F4, 4);
  play(NOTE_F4, 1);
  play(NOTE_GS4, 1);
  play(NOTE_AS5, 1);
  play(NOTE_AS5, 2);
  play(NOTE_GS4, 2);
  delay(3 * NOTE_DUR);
  play(NOTE_F4, 4);
  play(NOTE_F4, 1);
  play(NOTE_GS4, 1);
  play(NOTE_AS5, 1);
  play(NOTE_AS5, 2);
  play(NOTE_GS4, 2);
  play(NOTE_F4, 2);
  play(NOTE_E4, 1);
  play(NOTE_F4, 2);
  delay(2 * NOTE_DUR);
  play(NOTE_AS5, 1);
  play(NOTE_GS4, 1);
  play(NOTE_F4, 1);
  play(NOTE_DS4, 1);
  play(NOTE_F4, 8);
  delay(2 * NOTE_DUR);

  delay(8 * NOTE_DUR); // ending delay
}
*/

