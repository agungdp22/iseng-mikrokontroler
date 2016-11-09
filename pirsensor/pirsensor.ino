float sensor;
int relay = 8;
int count = 0;

void setup() {
  Serial.begin(9600); 
  pinMode(relay,OUTPUT);
}

void loop() {
  float sensor = analogRead(A0);
  Serial.println(sensor);
  Serial.println(count);
  if(sensor>200){
    digitalWrite(relay,HIGH);
    count++;
    if(count > 2){
      delay(600000);
    }
    else{
      delay(10000);
    }
  }
  else{
    count = 0;
    digitalWrite(relay,LOW);
    delay(10);
  }
}
