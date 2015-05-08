#include <SoftwareSerial.h>

char data;
SoftwareSerial bluetooth_card (8,7);

void setup() {
  bluetooth_card.begin(9600); // initialise le hc-05
  Serial.begin(9600); // initialise le port serie de l'arduino
}

void loop() {

  if (bluetooth_card.available()) {   
    data = bluetooth_card.read(); 
    Serial.println (data);
    delay (100);
  }

}


