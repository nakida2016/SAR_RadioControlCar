int BTReset = 3;
int LED = 13;
char inByte[2] = {-1, -1};         // incoming serial byte
String data;
  
void setup() {
  // make the Bluetooth Module reset:
  digitalWrite(BTReset, LOW);
  delay(100);
  digitalWrite(BTReset, HIGH);
  delay(500);

  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);

  pinMode(LED, OUTPUT);  // make a LED pin output
  Serial.println("TEST START"); 
}

void loop() {
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
      for(cnt = 0; cnt < 2; cnt++){
        Serial.print(inByte[cnt],DEC); 
        Serial.print(","); 
        inByte[cnt] = -1;
      }
      Serial.println("end"); 
    }
   }
   delay(10);        // delay in between reads for stability
}
