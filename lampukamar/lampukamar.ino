float sensor;
int led = 8;

void setup() {
  Serial.begin(9600); 
  pinMode(led, OUTPUT);
  digitalWrite(led,LOW);
}

void loop() {
  float sensor = analogRead(A0);
  Serial.println(sensor);
  if(sensor<1015){
     digitalWrite(led, LOW); 
  }
  else{
    digitalWrite(led, HIGH); 
  }
}
