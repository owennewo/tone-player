#ifndef SONG_H
#define SONG_H
#include <Arduino.h>

const float note_freq_map[109] = {
    16.35, 17.32, 18.35, 19.45, 20.6, 21.83, 23.12, 24.5, 25.96, 27.5, 29.14, 30.87,
    32.7, 34.65, 36.71, 38.89, 41.2, 43.65, 46.25, 49, 51.91, 55, 58.27, 61.74,
    65.41, 69.3, 73.42, 77.78, 82.41, 87.31, 92.5, 98, 103.83, 110, 116.54, 123.47,
    130.81, 138.59, 146.83, 155.56, 164.81, 174.61, 185, 196, 207.65, 220, 233.08, 246.94,
    261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392, 415.3, 440, 466.16, 493.88,
    523.25, 554.37, 587.33, 622.25, 659.25, 698.46, 739.99, 783.99, 830.61, 880, 932.33, 987.77,
    1046.5, 1108.73, 1174.66, 1244.51, 1318.51, 1396.91, 1479.98, 1567.98, 1661.22, 1760, 1864.66, 1975.53,
    2093, 2217.46, 2349.32, 2489.02, 2637.02, 2793.83, 2959.96, 3135.96, 3322.44, 3520, 3729.31, 3951.07,
    4186.01, 4434.92, 4698.63, 4978.03, 5274.04, 5587.65, 5919.91, 6271.93, 6644.88, 7040, 7458.62, 7902.13,
    0};

struct Tone
{
  byte note;  // index from #0 (C0 = 16.35Hz ) to #57 (A4=440Hz) and up to #107 (B8=7902Hz)
  byte ticks; // 256 ticks in a beat.  e.g. 1/8 note is 32 ticks and a dotted 1/4 is 96 ticks
};

struct Track
{
  Tone *tones;
  word tone_count;
  word tone_index = 0; // the current tone being played
  word tick_index = 0; // the current tick in the current tone being played
  float current_frequency = 0;

  Tone *getTone(byte _tone_index)
  {
    return &tones[_tone_index];
  }

  Tone *currentTone()
  {
    return getTone(tone_index);
  }

  bool finished()
  {
    return bool(tone_index > (tone_count - 1));
  }
};

struct Song
{
  Song(){};
  Track *tracks[4];
  byte tracks_count = 0;
  word bpm;

  Track *getTrack(byte track_index)
  {
    return tracks[track_index];
  }

  Track *newTrack(word _tone_count)
  {
    Track *track = new Track();
    track->tones = new Tone[_tone_count];
    track->tick_index = 0;
    track->tone_index = 0;
    track->tone_count = _tone_count;
    tracks[tracks_count] = track;
    tracks_count++;
    return track;
  }

  bool finished()
  {
    for (byte i = 0; i < tracks_count; i++)
    {
      if (!(*tracks[i]).finished())
      {
        return false;
      }
    }
    return true;
  }
  ~Song()
  {
    Serial.print("Deleting tracks: ");
    Serial.println(tracks_count);
    for (byte i = 0; i < tracks_count; i++)
    {
      delete &tracks[i];
    }
  }
};

// calculates tone duration in milliseconds
inline long toneDuration(int bpm, int tone_duration, bool dotted)
{
  long durationMillis = (60 * 1000L / bpm) * (4.0 / tone_duration);
  if (dotted)
  {
    durationMillis += durationMillis / 2;
  }
  return durationMillis;
}

// calculates tone duration in milliseconds
inline byte toneTicks(int tone_duration, bool dotted)
{
  int ticks = 256 / tone_duration;
  if (dotted)
  {
    ticks *= 1.5;
  }
  if (ticks > 255)
    ticks = 255;
  return byte(ticks);
}

// calculates tone note (e.g. C0 = 0, A6=57)
inline byte toneIndex(char tone_note, byte tone_octave, bool tone_sharp = false)
{

  int twelth_index = 0;
  switch (tone_note)
  {
  case 'c':
  case 'C':
    twelth_index = 0;
    break;
  case 'd':
  case 'D':
    twelth_index = 2;
    break;
  case 'e':
  case 'E':
    twelth_index = 4;
    break;
  case 'f':
  case 'F':
    twelth_index = 5;
    break;
  case 'g':
  case 'G':
    twelth_index = 7;
    break;
  case 'a':
  case 'A':
    twelth_index = 9;
    break;
  case 'b':
  case 'B':
  case 'h': // german
  case 'H':
    twelth_index = 11;
    break;
  case 'p':
  case 'P':
  default:
    return 108; // a pause, no frequency
  }
  if (tone_sharp)
    twelth_index++;

  int index = tone_octave * 12 + twelth_index;
  return index;
}
inline float toneFrequencyFromIndex(byte tone_index)
{
  //   const byte a4_index = 58;
  //   // formula from https://pages.mtu.edu/~suits/NoteFreqCalcs.html
  //   return 440.0 * pow(1.059463094359, tone_index - a4_index);
  return note_freq_map[tone_index];
}

inline float toneFrequency(char tone_note, int tone_octave, bool tone_sharp = false)
{
  byte tone_index = toneIndex(tone_note, tone_octave, tone_sharp);
  return toneFrequencyFromIndex(tone_index);
}

#endif