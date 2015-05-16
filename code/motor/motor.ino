const int input1 = 8;
const int input2 = 3;
const int pwm = 11;

int x = 0;
int sens = 0; // 0 pour incrementer - 1 pour decrementer

void setup() {
  
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(pwm, OUTPUT);

}

void loop() {

  analogWrite (pwm,x);
  if (sens = 0) {
    x++;
    if (x > 255) {
      sens = 1;
      x = 255;
    }
  }
  else {
    x--;
    if (x < 1) {
      sens = 0;
      x = 1;
    }    
  }

  delay (500);
  
}
