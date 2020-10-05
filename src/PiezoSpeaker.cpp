#include <Arduino.h>
#include <PiezoSpeaker.h>

// TODO: enable volume - it's fixed at max at the moment
PiezoSpeaker::PiezoSpeaker(int _pin, int _volume, int _note_offset)
    : Speaker(100, _note_offset)
{
    speaker_pin = _pin;
    pinMode(speaker_pin, OUTPUT);
}

void PiezoSpeaker::loop()
{
    if (enabled)
    {
        long now = micros();
        if (now - last_toggle_micros > half_period_micros)
        {
            speaker_state = !speaker_state;
            last_toggle_micros = now;
            digitalWrite(speaker_pin, speaker_state);
        }
    }
}
