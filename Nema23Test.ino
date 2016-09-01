#include <AccelStepper.h>

// Library downloaded from http://www.airspayce.com/mikem/arduino/AccelStepper/AccelStepper-1.53.zip
// Thanks

// Code lifted from http://forum.arduino.cc/index.php?topic=309868.5;wap2
// Thanks

/*
 General notes
 
 1. Wiring

 STP-DRV-80100 V+ -> 24V POWER SUPPLY
 STP-DRV-80100 V- -> 24V POWER SUPPLY
 STP-DRV-80100 A+ -> RED NEMA 34
 STP-DRV-80100 A- -> BLACK NEMA 34
 STP-DRV-80100 B+ -> WHITE NEMA 34
 STP-DRV-80100 B- -> GREEN NEMA 34
 STP-DRV-80100 DIR- -> Pin 9 ARDUINO MEGA
 STP-DRV-80100 DIR+ -> +5V ARDUINO MEGA
 STP-DRV-80100 STEP- -> PIN 8 ARDUINO MEGA
 STP-DRV-80100 STEP+ -> +5V ARDUINO MEGA

 2. Stepper Motor Driver
 
 STP-DRV-80100 13A Max rating
 
 3. Stepper Motor
 
 NEMA 34 H6SS155-5508-01
 
 3. Arduino Board
 
 Mega 2560
 
 4. IDE
 
 1.6.11
 
 5. 0S
 
 Windows 10.
 
 6. Hardware
 
 HP Stream
 
*/

// Define a stepper and the pins it will use
AccelStepper stepper(1,8,9);

void setup()
{ 
  stepper.setMaxSpeed(8000);
  stepper.setAcceleration(400);
}

void loop(){   
stepper.moveTo(13000);
  while (stepper.currentPosition() != 12000) // Full speed up to 300
    stepper.run();
  stepper.stop(); // Stop as fast as possible: sets new target
  stepper.runToPosition();
  // Now stopped after quickstop

  // Now go backwards
  stepper.moveTo(-13000);
  while (stepper.currentPosition() != 0) // Full speed basck to 0
    stepper.run();
  stepper.stop(); // Stop as fast as possible: sets new target
  stepper.runToPosition();
  // Now stopped after quickstop
}
