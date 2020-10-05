#include <Arduino.h>
#include <TonePlayer.h>
#include <PiezoSpeaker.h>

PiezoSpeaker speaker1 = PiezoSpeaker(PC0, 50, 0);
TonePlayer player;

void setup() {

  Serial.begin(115200);
  delay(750);
  Serial.println(F("** TONE PLAYER **"));
  player.attachSpeaker(&speaker1);
}

// tune: Old mac donald had a farm
float frequencies[] = { 
  toneFrequency('c', 5),
  toneFrequency('c', 5),
  toneFrequency('c', 5),
  toneFrequency('g', 4),
  toneFrequency('a', 4),
  toneFrequency('a', 4),
  toneFrequency('g', 4),
  toneFrequency('p', 0),
  toneFrequency('e', 5),
  toneFrequency('e', 5),
  toneFrequency('d', 5),
  toneFrequency('d', 5),
  toneFrequency('c', 5),
  toneFrequency('c', 5),
  toneFrequency('c', 5),
  toneFrequency('p', 0)
};

byte note_index = 0;

void loop() {

  if (player.isPlaying()) {
    player.loop();
  } else {
    delay(10); // space between notes
    float frequency = frequencies[note_index];
    player.playTone(frequency, 500);
    Serial.println(frequency);
    note_index++;
    if (note_index >= sizeof(frequencies)/sizeof(float)) {
      note_index = 0;
    }
  }
  
}
