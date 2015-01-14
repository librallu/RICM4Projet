#include <SoftwareSerial.h>

SoftwareSerial bridge(10,11);

void setup(){
  bridge.begin(9600); 
}

void loop(){
  bridge.write('a');
  bridge.write('b');
}
