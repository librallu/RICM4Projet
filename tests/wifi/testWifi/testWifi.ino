#include <SoftwareSerial.h>

// déclaration des pins de communication avec la puce
const int rxPin = 10;
const int txPin = 11;

SoftwareSerial puce = SoftwareSerial(rxPin,txPin);

void setup(){
  Serial.begin(9600);
  while(!Serial);
  puce.begin(115200);
  //puce.println("AT+RST"); // Reset de la puce
  delay(500);
  puce.println("AT+"); // Demande de scan des wifi
}

void loop(){
  if ( puce.available() ){
    Serial.write(puce.read());
  }  
}
