#ifndef _RTTTL_H
#define _RTTTL_H

#include <Arduino.h>
#include <Song.h>

// these tunes are in rtttl (ringtone) format.  Declared here for limited RAM
#define RTTTL_CROATIA "croatia:d=64,o=6,b=160:4f#,p,4f#,p,4f#.,p,8e,p,8e,p,8d,p,4d,p,2a5,p,8g5,p,8f#5,p,8g5,p,8a5,p,2b5,p,8a5,p,8g5,p,8f#5,p,8g5,p,2a5,p,4f#,p,4f#,p,4f#.,p,8e,p,8e,p,8d,p,4d,p,2a5,p,8g5,p,8f#5,p,8g5,p,8a5,p,2b5,p,8c#,p,8c#,p,4e,p,2d,p,4c#,p,4c#,p,4c#.,p,8b5,p,4c#,p,8c#,p,8d,p,4e.,p,8c#,p,8e,p,8e,p,8e,p,8e,p,4e,p,4d,p,4c#,p,4b5,p,2a5,p,4f#,p,4f#,p,4f#.,p,8e,p,8e,p,8d,p,4d,p,2a5,p,8g5,p,8f#5,p,8g5,p,8a5,2b5,p,8c#,p,p,8c#,p,4e,p,2d,2d,2p"
#define RTTTL_FRANCE "marseillai:d=4,o=5,b=160:2p.,16d,8d.,16d,g,g,a,a,d.6,8b,8g,16p,16g,8b.,16g,e,2c6,8a.,16f#,2g,p,8g.,16a,b,b,b,8c.6,16b,b,a,p,8a.,16b,c6,c6,c6,8d.6,16c6,2b,p,8d.6,16d6,d6,8b.,16g,d6,8b.,16g,2d,8p.,16d,8d.,16f#,2a,c6,8a.,16f#,a,g,2f,e,8g.,16g,g,8f#.,16g,2a.,8p,8a,a#.,8a#,8a#,8a#,8c6,8d6,2a.,8a#,8a,g.,8g,8g,8a#,8a,8g,g,8f#,2p,16d6,2d.6,16d6,8b.,16g,2a.,8p.,16d6,2d.6,16d6,8b.,16g,2a,8p,d,2g,p,a,2b,2p,2c6,d6,e6,2a,8p,e6,2d.6,16b,8c.6,16a,2g."
#define RTTTL_WALES "HenWladFynHadau:d=4,o=5,b=150:2p,2p,d#,g,f,d#,a#,g#,g,d#6,d#6,8c6,8d6,2d#6,c6,a#,g,d#,d#,d,d#,g,f,f,2f,a#,a#,a#,8g,8g#,a#,a#,d#6,d#6,d#6,8c6,8d6,2d#6,c6,a#,g,d#,8f,g.,f,1d#.,2a#.,2d#.6,a#,g,d#,d#,d,d#,2f,a#,2a#,8g,8g#,2a#,d#6,2d#6,8c6,8d6,2d#6,c6,a#,g,d#,8f,g.,f,1d#."
#define RTTTL_USA "AnthemUSA:d=4,o=5,b=130:32p,8g.,16e,c,e,g,2c6,8e6.,16d6,c6,e,f#,2g,g,e6.,8d6,c6,2h,8a.,16h,c6,c6,g,e,c"

#define RTTTL_SIMPSONS "Simpsons:d=4,o=5,b=160:32p,c.6,e6,f#6,8a6,g.6,e6,c6,8a,8f#,8f#,8f#,2g"
#define RTTTL_PINK_PANTHER "PinkPanther:d=16,o=5,b=80:e,f,4p,g,g#,4p,e,f,16,g,g#,16,c#6,c6,16,e,f,16,c6,4b,4p,32a#,32g#,32f,32d#,8f."

#define RTTTL_SUPER_MARIO_BROS "smb:d=4,o=5,b=180:8e6,8e6,8p,8e6,8p,8c6,e6,g6,p,g,p,c6,8p,g,8p,e,8p,a,b,8a#,a,8g.,8e6,8g6,a6,8f6,8g6,8p,e6,8c6,8d6,b,8p,c6,8p,g,8p,e,8p,a,b,8a#,a,8g.,8e6,8g6,a6,8f6,8g6,8p,e6,8c6,8d6,b,8p,p,8g6,8f#6,8f6,d#6,8e6,8p,8g#,8a,8c6,8p,8a,8c6,8d6,p,8g6,8f#6,8f6,d#6,8e6,8p,c7,8c7,c7,p,p,8g6,8f#6,8f6,d#6,8e6,8p,8g#,8a,8c6,8p,8a,8c6,8d6,p,d#6,8p,d6,8p,c6,p,2p"
#define RTTTL_SUPER_MARIO_BROS_BASS "smb_bass:d=4,o=5,b=180:8d4,8d4,8p,8d4,8p,8d4,d4,g4,p,g3,p,g4,8p,e4,8p,c4,8p,f4,g4,8f#4,f4,8e4.,8c,8e,f,8d,8e,8p,c,8a4,8b4,g4,8p,g4,8p,e4,8p,c4,8p,f4,g4,8f#4,f4,8e4.,8c,8e,f,8d,8e,8p,c,8a4,8b4,g4,8p,c4,8p,8g4,p,c,f4,8p,8c,c,f4,c4,8p,8g4,p,8g4,8c,2p,p,g4,c4,8p,8g4,p,c,f4,8p,8c,c,f4,c4,g#4,8p,a#4,8p,c,8p,8g4,g4,c4"
// Next is a 2 track 'ptttl' with tracks separated by |
#define RTTTL_SUPER_MARIO_BROS_POLY "smb:d=4,o=5,b=180:8e6,8e6,8p,8e6,8p,8c6,e6,g6,p,g,p,c6,8p,g,8p,e,8p,a,b,8a#,a,8g.,8e6,8g6,a6,8f6,8g6,8p,e6,8c6,8d6,b,8p,c6,8p,g,8p,e,8p,a,b,8a#,a,8g.,8e6,8g6,a6,8f6,8g6,8p,e6,8c6,8d6,b,8p,p,8g6,8f#6,8f6,d#6,8e6,8p,8g#,8a,8c6,8p,8a,8c6,8d6,p,8g6,8f#6,8f6,d#6,8e6,8p,c7,8c7,c7,p,p,8g6,8f#6,8f6,d#6,8e6,8p,8g#,8a,8c6,8p,8a,8c6,8d6,p,d#6,8p,d6,8p,c6,p,2p|8d4,8d4,8p,8d4,8p,8d4,d4,g4,p,g3,p,g4,8p,e4,8p,c4,8p,f4,g4,8f#4,f4,8e4.,8c,8e,f,8d,8e,8p,c,8a4,8b4,g4,8p,g4,8p,e4,8p,c4,8p,f4,g4,8f#4,f4,8e4.,8c,8e,f,8d,8e,8p,c,8a4,8b4,g4,8p,c4,8p,8g4,p,c,f4,8p,8c,c,f4,c4,8p,8g4,p,8g4,8c,2p,p,g4,c4,8p,8g4,p,c,f4,8p,8c,c,f4,c4,g#4,8p,a#4,8p,c,8p,8g4,g4,c4"

#endif

#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__)
#define MAX_RTTL_LENGTH 650
#define MAX_TONES_PER_TRACK 125
#else
#define MAX_RTTL_LENGTH 1300
#define MAX_TONES_PER_TRACK 250
#endif

// plays a nokia rtttl ringtone - spec: http://merwin.bespin.org/t4a/specs/nokia_rtttl.txt
// example format of rttl is:  rttl:"Simpsons:d=4,o=5,b=160:32p,c.6,e6,f#6,8a6,g.6,e6,c6,8a,8f#,8f#,8f#,2g";
Song *parseRTTL(const char *rtttl)
{

  int rttl_length = min((int)strlen_P(rtttl) + 1, MAX_RTTL_LENGTH);

  char rtttl_copy[rttl_length];
  // annoying memory mangement because UNO only has 2K!
  strncpy_P(rtttl_copy, rtttl, rttl_length);
  rtttl_copy[rttl_length] = 0; // put char terminator at end
  Serial.println(rtttl_copy);

  Song *song = new Song();

  // defaults
  int octave = 6;
  int duration = 4;

  // read three main sections which are separated by colons
  char *name_token = strtok(rtttl_copy, ":");
  char *control_tokens = strtok(NULL, ":");
  char *track_tokens = strtok(NULL, ":");

  song->bpm = 63; // default

  Serial.print(F("Parsing: "));
  Serial.println(name_token);

  // read and iterate through control tokens.  There are a maximum of 3 (default bpm, duration, octave)
  char *control_token = strtok(control_tokens, ",");
  while (control_token)
  {
    // avoid nested use of strtok
    char *save = NULL;
    char *control_key = strtok_r(control_token, "=", &save);
    int control_value = atoi(strtok_r(NULL, "=", &save));
    switch (control_key[0])
    {
    case 'o':
      octave = control_value;
      break;
    case 'd':
      duration = control_value;
      break;
    case 'b':
      song->bpm = control_value;
      break;
    }
    control_token = strtok(NULL, ",");
  }

  byte track_index = 0;
  // partial support for pttl (multiple tracks), doesn't support semicolon.
  char *track_token = strtok(track_tokens, "|");
  while (track_token)
  {
    word tone_index = 0;
    char *save = NULL;
    char *tone_token = strtok_r(track_token, ",", &save);
    Track *track = song->newTrack(MAX_TONES_PER_TRACK);
    Serial.print(F("Track "));
    Serial.print(track_index);
    Serial.print(F(":"));
    long total_ticks = 0;

    while (tone_token)
    {
      bool tone_dotted = false;
      bool tone_sharp = false;
      char tone_note = 0;
      int tone_duration = 0;
      int tone_octave = octave;
      int size = strlen(tone_token);
      for (int index = 0; index < size; index++)
      {
        char current = tone_token[index];
        if (current == '.')
        {
          tone_dotted = true;
        }
        else
        {
          if (isDigit(current))
          {
            // either a duration or an octave depending on position
            int value = current - 48;
            if (tone_note == 0)
            {
              tone_duration = 10 * tone_duration + value;
            }
            else
            {
              tone_octave = value;
            }
          }
          else if (current == '#')
          {
            tone_sharp = true;
          }
          else if (current == ' ')
          {
            continue; //ignore space
          }
          else
          {
            tone_note = current;
          }
        }
      }

      if (tone_duration == 0)
        tone_duration = duration;

      track->tones[tone_index].note = toneIndex(tone_note, tone_octave, tone_sharp);
      track->tones[tone_index].ticks = toneTicks(tone_duration, tone_dotted);
      total_ticks += track->tones[tone_index].ticks;

      Serial.print(F(" "));
      Serial.print(tone_note);
      Serial.print(tone_octave);
      if (tone_index == MAX_TONES_PER_TRACK - 1)
      {
        Serial.println(F("\n**** Warning - exceeded SRAM (crash may follow)"));
        break;
      }
      tone_index++;
      tone_token = strtok_r(NULL, ",", &save);
    }
    Serial.print(F(" ["));
    Serial.print(total_ticks);
    Serial.println(F(" ticks]"));

    track->tone_count = min(int(tone_index), int(MAX_TONES_PER_TRACK));
    track->tone_index = 0;
    track->tick_index = 0;

    track_index++;

    track_token = strtok(NULL, "|");
  }
  return song;
}