#include <Arduino.h>
#include <TonePlayer.h>
#include <PiezoSpeaker.h>
#include <RTTTL.h>

PiezoSpeaker speaker1 = PiezoSpeaker(PC0, 50, 0);

TonePlayer player;

const char *songs[] = {
    RTTTL_PINK_PANTHER,
    RTTTL_SIMPSONS,
    RTTTL_USA,
    RTTTL_SUPER_MARIO_BROS,
    RTTTL_SUPER_MARIO_BROS_POLY,
    RTTTL_WALES,
    RTTTL_FRANCE,
    RTTTL_CROATIA
};

int song_index = 0;
int song_count = sizeof(songs) / sizeof(char *);

void setup()
{
  Serial.begin(115200);
  delay(750);

  Serial.println(F("** JUKEBOX PLAYER **"));
  player.attachSpeaker(&speaker1);

  Song *song = parseRTTL(songs[song_index]);
  player.play(song);
}

void loop()
{
  if (player.isPlaying())
  {
    player.loop();
  }
  else
  {
    Serial.println("\nFinished");
    delay(2000);
    song_index++;
    if (song_index > song_count - 1)
      song_index = 0;

    Song *song = parseRTTL(songs[song_index]);
    player.play(song);
  }
}
