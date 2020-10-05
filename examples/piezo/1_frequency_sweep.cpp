#include <Arduino.h>
#include <TonePlayer.h>
#include <PiezoSpeaker.h>

PiezoSpeaker speaker1 = PiezoSpeaker(PC0, 50, 0);
TonePlayer player;

void setup() {

  Serial.begin(115200);
  delay(750);
  Serial.println(F("** SWEEP PLAYER **"));

  player.attachSpeaker(&speaker1);

}

int note_index = 108; //9th octave (highest note)

void loop() {

  if (player.isPlaying()) {
    player.loop();
  } else {
    // delay(10); // space between notes
    float frequency = toneFrequencyFromIndex(note_index);
    player.playTone(frequency, 30);
    Serial.println(frequency);
    note_index--;
    if (note_index < 0) {
      note_index = 108;
    }
  }
  player.loop();
  
}
