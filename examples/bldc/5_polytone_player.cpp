#include <Arduino.h>
#include <TonePlayer.h>
#include <BLDCSpeaker.h>
#include <BLDCMotor.h>
#include <RTTTL.h>

BLDCMotor motor1 = BLDCMotor(PB1, PB0, PA7, 15);
BLDCMotor motor2 = BLDCMotor(PA6, PA3, PA2, 15);
// BLDCMotor motor3 = BLDCMotor(PB9, PA1, PB8, 15);
BLDCSpeaker speaker1 = BLDCSpeaker(&motor1, 1.5, 10, -12);
BLDCSpeaker speaker2 = BLDCSpeaker(&motor2, 1.5, 100, -12);
TonePlayer player;
const char rtttl[] PROGMEM = RTTTL_SUPER_MARIO_BROS_POLY;

void setup() {

  Serial.begin(115200);
  delay(750);
  Serial.println(F("** POLY PLAYER **"));

  /* WARNING: ensure voltage_limit isn't too high - you could overheat motor or MOSFETS!! */
  motor1.voltage_limit = 1.0;
  motor1.init();

  /* WARNING: ensure voltage_limit isn't too high - you could overheat motor or MOSFETS!! */
  motor2.voltage_limit = 1.5;
  motor2.init();

  player.attachSpeaker(&speaker1);
  player.attachSpeaker(&speaker2);

  Song* song = parseRTTL(rtttl);
  player.play(song);
}

void loop() {
  if(player.isPlaying()) {
    player.loop();
  } else {
    Serial.println("\nFinished");
    delay(2000);
    Serial.println("\nReplay");
    player.replay();
  }
}
