#include <SoftwareSerial.h>

#define STOP 0
#define MARCHE 127
#define TURN 50
#define KLX 110


SoftwareSerial bluetooth_card (8,7);

//klaxon
const int klaxon = 9;

// pwm moteurs gauches
const int mt_g = 3;
//pwm moteurs droits
const int mt_d = 5;

//sens des moteurs gauches
const int b2 = 12;
const int b7 = 13;

//sens des moteurs droits
const int b10 = 10;
const int b15 = 11;


/*
bluetooth_card.available(); // retourne le nombre de caractère à lire
bluetooth_card.read();     // retourne le prochain caractère reçu
bluetooth_card.write(val);  // envoie le char "val" sur la voie série
 */


void setup() {
  bluetooth_card.begin(9600);// démarre la voie série à la vitesse speed
  Serial.begin(9600);
  
  pinMode(klaxon, OUTPUT);

  pinMode(mt_g, OUTPUT);
  pinMode(mt_d, OUTPUT);

  pinMode(b2, OUTPUT);
  pinMode(b7, OUTPUT);
  pinMode(b10, OUTPUT);
  pinMode(b15, OUTPUT);

  digitalWrite (b2, LOW);
  digitalWrite (b7, LOW);
  digitalWrite (b10, LOW);
  digitalWrite (b15, LOW);

}

unsigned long time1;
unsigned long time2;


void loop() {

  char dir;

  if (((time2 = millis()) - time1) > 1000) {
    analogWrite(9,0);
  }
  
  if (Serial.available()) {
    //  if (bluetooth_card.available()) {
    dir = Serial.read();
    // dir bluetooth_card.read();

    switch (dir) {

      //arreter la voiture
    case 'b' :
      Serial.println ("arret");

      analogWrite(mt_g,STOP);
      analogWrite(mt_d,STOP);

      digitalWrite (b2, LOW);
      digitalWrite (b7, LOW);
      digitalWrite (b10, LOW);
      digitalWrite (b15, LOW);

      break;
      
      //faire avancer la voiture
    case 'u' :
      Serial.println ("avance");

      digitalWrite (b2, LOW);
      digitalWrite (b7, HIGH);
      digitalWrite (b10, LOW);
      digitalWrite (b15, HIGH);

      analogWrite(mt_g,MARCHE);
      analogWrite(mt_d,MARCHE);

      break;

      //tourner à droite
    case 'r' :
      Serial.println ("droite");

      analogWrite(mt_g,MARCHE);
      analogWrite(mt_d,TURN);

      break;

      //tourner à gauche
    case 'l' :
      Serial.println ("gauche");

      analogWrite(mt_d,MARCHE);
      analogWrite(mt_g,TURN);

      break;

      //reculer
    case 'd' :
      Serial.println ("reculer");

      digitalWrite (b2, HIGH);
      digitalWrite (b7, LOW);
      digitalWrite (b10, HIGH);
      digitalWrite (b15, LOW);

      analogWrite(mt_d,MARCHE);
      analogWrite(mt_g,MARCHE);
      
      break;

      //klaxon
    case 'k' :
      Serial.println ("klaxon");
      analogWrite(9,KLX);
      time1 = millis();
      break;

    default :
      Serial.println ("mauvais");
      break;

    }
    
  }

}
	
