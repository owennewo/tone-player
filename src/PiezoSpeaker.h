#ifndef PIEZO_SPEAKER_H
#define PIEZO_SPEAKER_H
#include <Speaker.h>

class PiezoSpeaker : public Speaker
{

public:
    explicit PiezoSpeaker(int speaker_pin, int volume = 50, int note_offset = 0);
    void loop();

private:
    int speaker_pin;
};

#endif