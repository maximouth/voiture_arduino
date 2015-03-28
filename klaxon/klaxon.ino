
/*
 Piezo
 
 This example shows how to run a Piezo Buzzer on pin 9
 using the analogWrite() function.
 
 It beeps 3 times fast at startup, waits a second then beeps continuously
 at a slower pace
 
 */

void setup()  { 
  // declare pin 9 to be an output:
  pinMode(9, OUTPUT);
 } 

void loop()  { 
   beep(); 
  delay (2000);
}

void beep(){
  analogWrite(9,100);      // Almost any value can be used except 0 and 255
  delay (1000);
  analogWrite(9,0);      // Almost any value can be used except 0 and 255

}  
