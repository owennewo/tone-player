#include <Arduino.h>
#include <BLDCSpeaker.h>

BLDCSpeaker::BLDCSpeaker(BLDCMotor *_motor, float _voltage_limit, int _volume, int _note_offset)
    : Speaker(_volume, _note_offset)
{
    motor = _motor;
    setVolume(_volume);
    wave_shape = WaveShape::Square; // square is less cpu and sounds old school!

    motor->controller = ControlType::velocity_openloop;
    motor->voltage_limit = _voltage_limit;
}

void BLDCSpeaker::setVolume(float volume)
{
    amplitude = 0.5 * PI * volume / 100;
}

void BLDCSpeaker::setFrequency(float _frequency)
{
    if (frequency == 0) {
        disable();
    } else {
        enable();
    }
    start_micros = micros();
    Speaker::setFrequency(_frequency);
}

void BLDCSpeaker::enable()
{
    Speaker::enable();
}

void BLDCSpeaker::disable()
{
    motor->setPhaseVoltage(0, 0);
    Speaker::disable();
}

void BLDCSpeaker::loop()
{
    if (enabled)
    {
        long now = _micros();
        if (wave_shape == WaveShape::Square)
        {
            if (now - last_toggle_micros > half_period_micros)
            {
                speaker_state = !speaker_state;
                last_toggle_micros = now;
                motor->setPhaseVoltage(motor->voltage_limit, (speaker_state * amplitude));
            }
        }
        else if (wave_shape == WaveShape::Sinusoidal)
        {
            float diff = (now - start_micros);
            float angle = sin(PI * diff / half_period_micros) * amplitude;
            motor->setPhaseVoltage(motor->voltage_limit, angle);
        }
        else
        {
            Serial.println("unknown wavetype");
            motor->setPhaseVoltage(0, angle);
        }
    }
}