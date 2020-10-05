#include <Arduino.h>
#include <TonePlayer.h>
#include <BLDCSpeaker.h>
#include <BLDCMotor.h>

BLDCMotor motor1 = BLDCMotor(PB1, PB0, PA7,15, PA4);
BLDCSpeaker speaker1 = BLDCSpeaker(&motor1, 1.5, 50, 0);
TonePlayer player;

void setup() {

  Serial.begin(115200);
  delay(750);

  /* WARNING: ensure voltage_limit isn't too high - you could overheat motor or MOSFETS!! */
  motor1.voltage_limit = 1.5;
  motor1.init();

  Serial.println(F("** SERIAL PLAYER **"));
  player.attachSpeaker(&speaker1);

  Serial.println(F("Copy and paste '6cdec cdec efgp efgp +gagf-ec +gagf-ec c5g6cp c5g6-c' into your Serial console or 'type' your own song"));
}

void playNotesFromSerial()
{

  static int octave = 5;
  static int duration = 400;

  // a string to hold incoming data
  static String received_chars;
  if (Serial.available())
  {
    char inChar = (char)Serial.read();
    if (isDigit(inChar))
    {
      octave = atoi(&inChar);
      Serial.print(F("Octave is now: ")); Serial.println(octave);
    }
    else if (isWhitespace(inChar))    {
      // ignore
    }
    else if (inChar == '-')
    {
      Serial.println(F("Half Speed"));
      duration *= 2; // slow it down
    }
    else if (inChar == '+')
    {
      Serial.println(F("Double Speed"));
      duration /= 2; // speed it up
    }
    else if (isAlpha(inChar))
    {
      // char note = inChar;
      float freq = toneFrequency((char) inChar, octave, false);
      Serial.print(F("Playing: ")); Serial.print(inChar); Serial.println(octave);
      player.playTone(freq, duration);
    }
    else
    {
      Serial.println(F("bad character, try pasting with mouse not keyboard!"));
    }
  }
}

void loop() {
  
  if (player.isPlaying()) {
    player.loop();
  } else {
    playNotesFromSerial();
  }
  
}
