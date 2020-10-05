#include <Arduino.h>
#include <TonePlayer.h>

TonePlayer::TonePlayer()
{
  bpm = 120;
}

void TonePlayer::attachSpeaker(Speaker *_speaker)
{
  speakers[speaker_count] = _speaker;
  speaker_count++;
}

void TonePlayer::playTone(float freq, long duration_msec)
{
  for (byte speaker_index = 0; speaker_index < speaker_count; speaker_index++)
  {
    speakers[speaker_index]->setFrequency(freq);
    if (freq == 0) {
      speakers[speaker_index]->disable();
    } else {
      speakers[speaker_index]->enable();
    }
  }
  tick_next_micros = micros() + duration_msec * 1000;
}

void TonePlayer::play(Song *song)
{
  current_song = song;
  tick_duration_micros = 1e6 * 60 * 4 / (song->bpm * 256);
  tick_next_micros = micros();
  for (byte track_index = 0; track_index < current_song->tracks_count; track_index++)
  {
    current_song->tracks[track_index]->tone_index = 0;
  }
  for (byte speaker_index = 0; speaker_index < speaker_count; speaker_index++)
  {
    speakers[speaker_index]->enable();
  }
}

void TonePlayer::replay()
{
  if (current_song != nullptr)
  {
    play(current_song);
  }
}

void TonePlayer::loop()
{
  unsigned long now = micros();
  if (now > tick_next_micros)
  {
    if (current_song != nullptr)
    {
      tickSong(current_song);
      tick_next_micros = now + tick_duration_micros;
    }
  }

  for (byte speaker_index = 0; speaker_index < speaker_count; speaker_index++)
  {
    speakers[speaker_index]->loop();
  }
}

void TonePlayer::tickTrack(Track *track)
{
  if (track->tick_index >= track->currentTone()->ticks)
  {
    track->tone_index++;
    track->tick_index = 0;
  }

  if (!track->finished())
  {
    if (track->tick_index == 0)
    {
      track->current_frequency = note_freq_map[track->currentTone()->note];
      Serial.print("|");
      Serial.print(track->current_frequency);
    }
    track->tick_index++;
  }
}

void TonePlayer::tickSong(Song *song)
{
  for (byte track_index = 0; track_index < song->tracks_count; track_index++)
  {
    Track *track = song->getTrack(track_index);
    tickTrack(track);
  }
  for (byte speaker_index = 0; speaker_index < speaker_count; speaker_index++)
  {
    // some speakers may need to share a track if speaker_count > tracks_count
    Track *track = song->getTrack(speaker_index % song->tracks_count);
    if (track->finished())
    {
      speakers[speaker_index]->disable();
    }
    else
    {
      speakers[speaker_index]->setFrequency(track->current_frequency);
      speakers[speaker_index]->setVolume(100);
    }
  }
}

bool TonePlayer::isPlaying()
{
  if (current_song != nullptr)
  {
    return !current_song->finished();
  }
  else
  {
    // check if tone is playing
    if (tick_next_micros < micros())
    {
      for (byte speaker_index = 0; speaker_index < speaker_count; speaker_index++)
      {
        speakers[speaker_index]->disable();
      }
      return false;
    }
    return true;
  }
}
