#include <Arduino.h>
#include <TonePlayer.h>
#include <BLDCSpeaker.h>
#include <BLDCMotor.h>

BLDCMotor motor1 = BLDCMotor(PB1, PB0, PA7,15, PA4);
BLDCSpeaker speaker1 = BLDCSpeaker(&motor1, 1.5, 50, 0);
TonePlayer player;

void setup() {

  Serial.begin(115200);
  delay(750);
  Serial.println(F("** SWEEP PLAYER **"));

  motor1.controller = ControlType::velocity_openloop;
  motor1.voltage_power_supply = 12;
  /* WARNING: ensure voltage_limit isn't too high - you could overheat motor or MOSFETS!! */
  motor1.voltage_limit = 1.5;
  motor1.init();

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