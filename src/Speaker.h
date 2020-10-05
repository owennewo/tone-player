#ifndef SPEAKER_H
#define SPEAKER_H

class Speaker
{

public:
    Speaker(int _volume = 50, int _note_offset = 0)
    {
        volume = _volume;
        frequency_offset = pow(1.059463094359, _note_offset);
    }

    virtual void enable()
    {
        enabled = true;
        setVolume(volume);
    }

    virtual void disable()
    {
        enabled = false;
        setVolume(0);
    }

    virtual void setFrequency(float _frequency)
    {
        frequency = _frequency;
        half_period_micros = 1000000.0 / (2.0 * (_frequency * frequency_offset));
    }

    virtual void setVolume(float _volume)
    {
        volume = _volume;
    }

    virtual void loop(){};

protected:
    float frequency;
    float volume;
    float frequency_offset;
    long half_period_micros; // time taken for half an oscillation
    long last_toggle_micros = 0;
    bool speaker_state;
    bool enabled;
};

#endif