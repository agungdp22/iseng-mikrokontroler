/*
Agung Dwi Prasetyo
G64130073
*/

float sensor;
int buzzer = 9;
int led = 8;

void setup() {
  Serial.begin(9600); 
  pinMode(buzzer,OUTPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  float sensor = analogRead(A0);
  Serial.println(sensor);
  if(sensor>200){
    digitalWrite(buzzer,HIGH);
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(buzzer,LOW);
    digitalWrite(led,LOW);
  }
  delay(500);
}
