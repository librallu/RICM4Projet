#include <SoftwareSerial.h>

SoftwareSerial bridge(10,11);

void setup(){
  Serial.begin(9600);
  bridge.begin(9600);  
}

void loop(){
  if ( bridge.available() > 0 )
    Serial.write(bridge.read());
}
