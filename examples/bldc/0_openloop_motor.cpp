#include <Arduino.h>
#include <SimpleFOC.h>
#include <BLDCSpeaker.h>

BLDCMotor motor1 = BLDCMotor(PB1, PB0, PA7,15, PA4);

void setup() {

  Serial.begin(115200);
  delay(750);
  Serial.println("** OPENLOOP MOTOR (No music, just turns - helps find the right voltage_limit) **");
  
  /* WARNING: ensure voltage_limit isn't too high - you could overheat motor or MOSFETS!! */
  motor1.voltage_limit = 1.5;
  motor1.init();
  
}

float electrical_angle = 0.0;

void loop() {
  
  // the motor should rotate.  If it doesn't move smoothly increase voltage_limit whilst checking temperature
  // of motors and Driver/MOSFETS 
  electrical_angle += 0.005;
  motor1.setPhaseVoltage(motor1.voltage_limit, electrical_angle);
  
}
