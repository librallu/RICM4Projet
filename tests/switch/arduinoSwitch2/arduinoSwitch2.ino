#include <SoftwareSerial.h>

// déclaration des pins de réception de donnée
const int rxPin = 10;
const int txPin = 11;

SoftwareSerial bridge = SoftwareSerial(rxPin,txPin);

void setup(){
  bridge.begin(9600); 
}

void loop(){
  bridge.write('a');
  bridge.write('b');
}
