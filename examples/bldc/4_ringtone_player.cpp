#include <Arduino.h>
#include <TonePlayer.h>
#include <BLDCSpeaker.h>
#include <BLDCMotor.h>
#include <RTTTL.h>

BLDCMotor motor1 = BLDCMotor(PB1, PB0, PA7, 15);
BLDCSpeaker speaker1 = BLDCSpeaker(&motor1, 1.5, 10, -12);

TonePlayer player;
const char rtttl[] PROGMEM = RTTTL_PINK_PANTHER;

void setup() {

  Serial.begin(115200);
  delay(750);
  Serial.println(F("** RTTTL PLAYER **"));

  /* WARNING: ensure voltage_limit isn't too high - you could overheat motor or MOSFETS!! */
  motor1.voltage_limit = 1.5;
  motor1.init();

  player.attachSpeaker(&speaker1);

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
