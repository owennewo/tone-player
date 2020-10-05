
#ifndef TonePlayer_H
#define TonePlayer_H

#include <Song.h>
#include <Speaker.h>

class TonePlayer
{

public:
    TonePlayer();
    void attachSpeaker(Speaker *speaker);
    void play(Song *song);
    void playTone(float freq, long duration_msec = 400);
    void replay();
    bool isPlaying();
    void loop();

private:
    int bpm;
    void tickSong(Song *song);
    void tickTrack(Track *song);
    Song *current_song = nullptr;
    Speaker *speakers[4];
    unsigned long tick_duration_micros;
    unsigned long tick_next_micros;
    int speaker_count = 0;
};

#endif