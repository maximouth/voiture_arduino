const int spk = 9;
int x = 0;


void setup()  { 
  // declare pin 9 to be an output:
  pinMode(spk, OUTPUT);
 } 

void loop()  { 
  beep(); 
  x = (x+1)%256;
  delay (2000);
}

void beep(){
  analogWrite(spk,x);      // x va prendre une valeur differente à chaque tour
  delay (1000);
  analogWrite(spk,0); 
}  
