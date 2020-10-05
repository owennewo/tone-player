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
  Serial.println(F("** TONE PLAYER **"));

  motor1.controller = ControlType::velocity_openloop;
  motor1.voltage_power_supply = 12;
  /* WARNING: ensure voltage_limit isn't too high - you could overheat motor or MOSFETS!! */
  motor1.voltage_limit = 1.5;
  motor1.init();

  player.attachSpeaker(&speaker1);

}

// tune: Old mac donald had a farm
float frequencies[] = { 
  toneFrequency('c', 6),
  toneFrequency('c', 6),
  toneFrequency('c', 6),
  toneFrequency('g', 5),
  toneFrequency('a', 5),
  toneFrequency('a', 5),
  toneFrequency('g', 5),
  toneFrequency('p', 0),
  toneFrequency('e', 6),
  toneFrequency('e', 6),
  toneFrequency('d', 6),
  toneFrequency('d', 6),
  toneFrequency('c', 6),
  toneFrequency('c', 6),
  toneFrequency('c', 6),
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
