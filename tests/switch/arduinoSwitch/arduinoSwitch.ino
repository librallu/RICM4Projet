#include <SoftwareSerial.h>

// déclaration des pins de réception de donnée
const int rxPin = 10;
const int txPin = 11;

SoftwareSerial bridge = SoftwareSerial(rxPin,txPin);

void setup(){
  Serial.begin(9600);
  bridge.begin(9600);
}

void loop(){
  if ( bridge.available() ) // Si de l'information est disponible
    Serial.write(bridge.read()); // On lit les données sur le bridge et on écrit sur le serial
}
