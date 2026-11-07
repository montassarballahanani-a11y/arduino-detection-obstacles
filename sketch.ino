



const int led = 3;
const int trig = 9;
const int echo = 10;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duree = pulseIn(echo, HIGH, 30000);
  float distance = duree * 0.0343 / 2;

  Serial.println(distance);

  if ( distance < 10) {
    digitalWrite(led, HIGH);
    tone(6, 2000);}
    else if( distance < 20){ 
      digitalWrite(led, HIGH);
      tone(6, 1000);}


    
   else {
    digitalWrite(led, LOW);
    noTone(6);
  }
  

  delay(100);
}

