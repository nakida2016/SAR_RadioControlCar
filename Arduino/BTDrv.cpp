#include "arduino.h"
#include "PinIO.h"
#include "servDrv.h"
#include "motDrv.h"

char inByte[2] = {-1, -1};         // incoming serial byte
String data;

void BTReset(){
  // make the Bluetooth Module reset:
  digitalWrite(BT_RESET, LOW);
  delay(100);
  digitalWrite(BT_RESET, HIGH);
  delay(500);

  Serial.println("BTReset OK"); 
}


void BTMain(){
   int cnt;

   // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) {
    // get incoming byte:
    for(cnt = 0; cnt < 2; cnt++){
      if(inByte[cnt] == -1){
        inByte[cnt] = Serial.read();
      }
      if((inByte[cnt] < 33)
      || (inByte[cnt] > 126)){
        inByte[0] = -1;
        inByte[1] = -1;
        break;
      }
    }
    if (inByte[1] != -1) {
      // コマンド解析
      switch(inByte[0]){
        case 'L':  hdrTurnLeft(inByte[1]);   break;
        case 'R':  hdrTurnRight(inByte[1]);  break;
        case 'F':  hdrDriveFront(inByte[1]);  break;
        case 'B':  hdrDriveBack(inByte[1]);  break;
        default: break;
      }
      for(cnt = 0; cnt < 2; cnt++){
        Serial.print(inByte[cnt],HEX); 
        Serial.print(","); 
        inByte[cnt] = -1;
      }
      Serial.println("end"); 
    }
   } 
   delay(10);        // delay in between reads for stability
}


