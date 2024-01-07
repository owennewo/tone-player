#include <SimpleFOC.h>
#include <TonePlayer.h>
#include <BLDCSpeaker.h>
#include <RTTTL.h>

BLDCMotor motor = BLDCMotor(7);
BLDCDriver6PWM driver = BLDCDriver6PWM(PA8, PB13, PA9, PB14, PA10, PB15, PC4);

BLDCSpeaker speaker1 = BLDCSpeaker(&motor, 1.5, 50, 0);
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

int song_index = 2;
int song_count = sizeof(songs) / sizeof(char *);

void setup()
{
  Serial.begin(115200);
  delay(750);

    // driver config
  // power supply voltage [V]
  driver.voltage_power_supply = 9;
  // limit the maximal dc voltage the driver can set
  // as a protection measure for the low-resistance motors
  // this value is fixed on startup
  driver.voltage_limit = 1;
  driver.init();
  // link the motor and the driver
  motor.linkDriver(&driver);

  // limiting motor movements
  // limit the voltage to be set to the motor
  // start very low for high resistance motors
  // currnet = resistance*voltage, so try to be well under 1Amp
  motor.voltage_limit = 0.01;   // [V]
  // limit/set the velocity of the transition in between 
  // target angles
  motor.velocity_limit = 5; // [rad/s] cca 50rpm
  // open loop control config
  motor.controller = MotionControlType::velocity_openloop;

  // init motor hardware
  motor.init();

  Serial.println(F("** JUKEBOX PLAYER **"));
    /* WARNING: ensure voltage_limit isn't too high - you could overheat motor or MOSFETS!! */

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
