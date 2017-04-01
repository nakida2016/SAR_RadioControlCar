#include "arduino.h"
#include "PinIO.h"

//-----------------------------------------------------------------
// LED点滅
//-----------------------------------------------------------------
void ledBlink(){  
  static int ledState = LOW;
  digitalWrite(WORKING_LED,ledState);
  ledState =! ledState;
}
