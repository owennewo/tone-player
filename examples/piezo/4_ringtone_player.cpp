#include <Arduino.h>
#include <TonePlayer.h>
#include <PiezoSpeaker.h>
#include <RTTTL.h>

PiezoSpeaker speaker1 = PiezoSpeaker(2, 50, 0);

TonePlayer player;
const char rtttl[] PROGMEM = RTTTL_PINK_PANTHER;

void setup() {
  Serial.begin(115200);
  delay(750);
  Serial.println(F("** RTTTL PLAYER **"));
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
