#ifndef BLDC_SPEAKER_H
#define BLDC_SPEAKER_H
#include <BLDCMotor.h>
#include <Speaker.h>

enum WaveShape
{
    Square,
    Sinusoidal,
};

class BLDCSpeaker : public Speaker
{

public:
    BLDCSpeaker(BLDCMotor *motor, float _voltage_limit, int volume = 50, int note_offset = 0);
    void setVolume(float volume);
    void setFrequency(float frequency);
    void enable();
    void disable();
    void loop();

private:
    BLDCMotor *motor;
    int setPhaseVoltage(float volts, float angle);
    float start_micros = 0;
    float amplitude = 0;
    WaveShape wave_shape;
};

#endif