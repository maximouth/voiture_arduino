const int trig = 4;
const int echo = 2;

int distance;
int duration;

void setup() {
  Serial.begin(9600);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(15);                  // must keep the trig pin high for at least 10us
  digitalWrite(trig, LOW);
  
  duration = pulseIn(echo, HIGH);
  distance = (duration/2)/29;
  //  duration = pulseIn(echo, LOW); a priori inutile
  Serial.println ( distance );
  // Serial.println  ("cm");

  delay (500);
  
}

