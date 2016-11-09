void setup() {
  pinMode(12,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int baca = analogRead(A0);
  Serial.println(baca);
  if(baca<1000) digitalWrite(12,HIGH);
  else digitalWrite(12,LOW);
  //delay(1000);
}
